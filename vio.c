#define  INCL_DOSPROCESS
#define  INCL_DOSSESMGR
#define  INCL_WINSHELLDATA
#include <os2.h>
#include <stdlib.h>

char   pels[] =                 /* w,h */
            {  8,8,    8,8,                     /* 0, 1,           */
               8,8,    6,10,   8,10,   8,12,    /* 2, 3, 4, 5,     */
               6,14,   8,14,   7,15,   8,16,    /* 6, 7, 8, 9,     */
               12,16,  8,18,  10,18,  12,20,    /* 10, 11, 12, 13, */
               12,22,  7,25,  12,30       };    /* 14, 15, 16      */

int    p = 0;

CHAR   cs[2];
ULONG  ccs = sizeof(cs);

char  *Shield       = "Shield";
char  *FontSize     = "~Font Size...";

char  *pgmname      = "CMD.EXE";
char  *title        = "CMD.EXE";
char   cmdline[512] = { '/','K',0 };

char   failer[CCHMAXPATH];

STARTDATA sd;
ULONG     sid;
PID       pid;

/* syntax: VIO n "title" command-line */

int main( int argc, char *argv[] )
{
  APIRET rc;

  WinInitialize(0);

  if ( argc > 1 ) { p = atoi(argv[1]); if ( p > 16 ) p = 0; }

  if ( argc > 2 ) { if ( *(argv[2]) != 0 ) title = argv[2]; }

  if ( argc > 3 ) { int i; char *a, *b;
                    cmdline[0] = ' ';
                    a = cmdline;
                    for ( i = 3; i < argc; i++ )
                    { for ( b = argv[i]; *b; *a++ = *b++ ); *a++ = ' '; }
                    *(--a) = 0;
                  }

  sd.Length         = sizeof(sd);
  sd.Related        = SSF_RELATED_INDEPENDENT;
  sd.FgBg           = SSF_FGBG_FORE;
  sd.TraceOpt       = SSF_TRACEOPT_NONE;
  sd.PgmTitle       = title;
  sd.PgmName        = pgmname;
  sd.PgmInputs      = cmdline;
  sd.TermQ          = 0;
  sd.Environment    = 0;
  sd.InheritOpt     = SSF_INHERTOPT_SHELL;
  sd.SessionType    = SSF_TYPE_WINDOWABLEVIO;
  sd.IconFile       = 0;
  sd.PgmHandle      = 0;
  sd.PgmControl     = SSF_CONTROL_VISIBLE;
  sd.InitXPos       = 0;
  sd.InitYPos       = 0;
  sd.InitXSize      = 0;
  sd.InitYSize      = 0;
  sd.Reserved       = 0;
  sd.ObjectBuffer   = failer;
  sd.ObjectBuffLen  = sizeof(failer);

  if ( PrfQueryProfileData( HINI_USERPROFILE, Shield, FontSize, cs, &ccs ) &&
       PrfWriteProfileData( HINI_USERPROFILE, Shield, FontSize, pels+(p*2), ccs ) )
  {
    rc = DosStartSession( &sd, &sid, &pid );
    DosSleep(500);

    PrfWriteProfileData( HINI_USERPROFILE, Shield, FontSize, cs, ccs );
  }

  return rc;
}
