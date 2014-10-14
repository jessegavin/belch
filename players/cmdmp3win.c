// cmdmp3win
// A command-line MP3 player for Windows
// (window-mode version)
//
// License: MIT / X11
// Copyright (c) 2009 by James K. Lawless
// jimbo@radiks.net http://www.radiks.net/~jimbo
// http://www.mailsend-online.com
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.



#include <windows.h>
#include <string.h>

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment(lib, "user32.lib")

char msg[256];

extern int __argc;
extern char ** __argv;


void sendCommand(char *);

int WINAPI WinMain( HINSTANCE hInstance, 
					HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, 
					int nCmdShow ) {

   char shortBuffer[MAX_PATH];
   char cmdBuff[MAX_PATH + 64];
   
   if(__argc<2) {
      sprintf(msg,"Syntax:\n\tcmdmp3win \"c:\\path to file\\file.mp3\"\n");
      MessageBox(NULL,msg,"cmdmp3win",MB_OK);
      return 1;
   }
      // Get the shortened path because the MCI string interpreter uses spaces
      // as a separator.  If spaces appear in the commands, parts of the filename
      // would be interpreted as paramters to the given command.
   GetShortPathName(__argv[1],shortBuffer,sizeof(shortBuffer));
   if(!*shortBuffer) {
      sprintf(msg,"Cannot shorten filename \"%s\"\n",__argv[1]);
      MessageBox(NULL,msg,"cmdmp3win",MB_OK);
      return 1;
   }   
   sendCommand("Close All");

   sprintf(cmdBuff,"Open %s Type MPEGVideo Alias theMP3",shortBuffer);
   sendCommand(cmdBuff);

   sendCommand("Play theMP3 Wait");
   return 0;
}

   // Send a string to the Media Control Interface
   // If an error occurs, display it and the string
   // that produced the error.
void sendCommand(char *s) {
   int i;
   i=mciSendString(s,NULL,0,0);
   if(i) {
         sprintf(msg,"Error %d when sending %s\n",i,s);
         MessageBox(NULL,msg,"cmdmp3win",MB_OK);
   }
}
