
       files:  readme.txt - this file
               vio        - makefile
               vio.c      - source
               vio.exe    - executable

 description:  A small program that demonstrates one way of
               starting VIO windows with different System VIO
               font sizes.  It works by changing the saved
               font size in the USER .ini file before starting
               the window.  The program saves and restores
               the prior saved-font-size.

      syntax:  VIO size title p1 ... pn

               where:  size  - font size [see table below]
                       title - window title
                       p1..n - CMD.EXE parameters

     example:  VIO  3  "A small window"  /k "dir /w /p"

               This will start a VIO window with using
               the 8x8 System VIO font with the title
               "A small window".  Then, the parameters
               '/k "dir /w /p"' will be passed to CMD.EXE.

  font sizes:  size - Height Width

                 2  -     8 x 8
                 3  -    10 x 6
                 4  -    10 x 8
                 5  -    12 x 8
                 6  -    14 x 6
                 7  -    14 x 8
                 8  -    15 x 7
                 9  -    16 x 8
                10  -    16 x 12
                11  -    18 x 8
                12  -    18 x 10
                13  -    20 x 12
                14  -    22 x 12
                15  -    25 x 7
                16  -    30 x 12

     caveats:  The .ini file application and key used
               to change the font size is undocumented.
               Usual Mission Impossible disclaimer here.

  comments &
 suggestions:  Welcome!

      author:  Ben Ravago
               bjr@hq.sequel.net

