/*
MIT License

Copyright (c) 2020 mrdcvlsc

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#ifndef VIRTUAL_TYPER_H
#define VIRTUAL_TYPER_H

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void mouse_DownClick(int pos_X, int pos_Y){
     SetCursorPos(pos_X,pos_Y);
     cout<<"mouse: right click HOLD - coordinate : ("<<pos_X<<','<<pos_Y<<')'<<endl;
     //cout<<"\nwait for 6 sec..."<<endl;
     Sleep(200);
     mouse_event(MOUSEEVENTF_LEFTDOWN,pos_X,pos_Y,0,0);
     Sleep(200);
}

void mouse_UPClick(int pos_X, int pos_Y){
     SetCursorPos(pos_X,pos_Y);
     cout<<"mouse: right click RELEASE HOLD - coordinate : ("<<pos_X<<','<<pos_Y<<')'<<endl;
     //cout<<"wait for 6 sec..."<<endl;
     Sleep(200);
     mouse_event(MOUSEEVENTF_LEFTUP,pos_X,pos_Y,0,0);
     Sleep(200);
}

void virtual_key_press(char char_input){

     switch(char_input){
               
          case 'a':
               keybd_event(0x41,0,0,0);
               keybd_event(0x41,0,KEYEVENTF_KEYUP,0);
               break;
          case 'b':
               keybd_event(0x42,0,0,0);
               keybd_event(0x42,0,KEYEVENTF_KEYUP,0);
               break;
          case 'c':
               keybd_event(0x43,0,0,0);
               keybd_event(0x43,0,KEYEVENTF_KEYUP,0);
               break;
          case 'd':
               keybd_event(0x44,0,0,0);
               keybd_event(0x44,0,KEYEVENTF_KEYUP,0);
               break;
          case 'e':
               keybd_event(0x45,0,0,0);
               keybd_event(0x45,0,KEYEVENTF_KEYUP,0);
               break;
          case 'f':
               keybd_event(0x46,0,0,0);
               keybd_event(0x46,0,KEYEVENTF_KEYUP,0);
               break;
          case 'g':
               keybd_event(0x47,0,0,0);
               keybd_event(0x47,0,KEYEVENTF_KEYUP,0);
               break;
          case 'h':
               keybd_event(0x48,0,0,0);
               keybd_event(0x48,0,KEYEVENTF_KEYUP,0);
               break;
          case 'i':
               keybd_event(0x49,0,0,0);
               keybd_event(0x49,0,KEYEVENTF_KEYUP,0);
               break;
          case 'j':
               keybd_event(0x4A,0,0,0);
               keybd_event(0x4A,0,KEYEVENTF_KEYUP,0);
               break;
          case 'k':
               keybd_event(0x4B,0,0,0);
               keybd_event(0x4B,0,KEYEVENTF_KEYUP,0);
               break;
          case 'l':
               keybd_event(0x4C,0,0,0);
               keybd_event(0x4C,0,KEYEVENTF_KEYUP,0);
               break;
          case 'm':
               keybd_event(0x4D,0,0,0);
               keybd_event(0x4D,0,KEYEVENTF_KEYUP,0);
               break;
          case 'n':
               keybd_event(0x4E,0,0,0);
               keybd_event(0x4E,0,KEYEVENTF_KEYUP,0);
               break;
          case 'o':
               keybd_event(0x4F,0,0,0);
               keybd_event(0x4F,0,KEYEVENTF_KEYUP,0);
               break;
          case 'p':
               keybd_event(0x50,0,0,0);
               keybd_event(0x50,0,KEYEVENTF_KEYUP,0);
               break;
          case 'q':
               keybd_event(0x51,0,0,0);
               keybd_event(0x51,0,KEYEVENTF_KEYUP,0);
               break;
          case 'r':
               keybd_event(0x52,0,0,0);
               keybd_event(0x52,0,KEYEVENTF_KEYUP,0);
               break;
          case 's':
               keybd_event(0x53,0,0,0);
               keybd_event(0x53,0,KEYEVENTF_KEYUP,0);
               break;
          case 't':
               keybd_event(0x54,0,0,0);
               keybd_event(0x54,0,KEYEVENTF_KEYUP,0);
               break;
          case 'u':
               keybd_event(0x55,0,0,0);
               keybd_event(0x55,0,KEYEVENTF_KEYUP,0);
               break;
          case 'v':
               keybd_event(0x56,0,0,0);
               keybd_event(0x56,0,KEYEVENTF_KEYUP,0);
               break;
          case 'w':
               keybd_event(0x57,0,0,0);
               keybd_event(0x57,0,KEYEVENTF_KEYUP,0);
               break;
          case 'x':
               keybd_event(0x58,0,0,0);
               keybd_event(0x58,0,KEYEVENTF_KEYUP,0);
               break;
          case 'y':
               keybd_event(0x59,0,0,0);
               keybd_event(0x59,0,KEYEVENTF_KEYUP,0);
               break;
          case 'z':
               keybd_event(0x5A,0,0,0);
               keybd_event(0x5A,0,KEYEVENTF_KEYUP,0);
               break;
          case 'A'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x41,0,0,0);
               keybd_event(0x41,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'B'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x42,0,0,0);
               keybd_event(0x42,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'C'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x43,0,0,0);
               keybd_event(0x43,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'D'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x44,0,0,0);
               keybd_event(0x44,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'E'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x45,0,0,0);
               keybd_event(0x45,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'F'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x46,0,0,0);
               keybd_event(0x46,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'G'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x47,0,0,0);
               keybd_event(0x47,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'H'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x48,0,0,0);
               keybd_event(0x48,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'I'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x49,0,0,0);
               keybd_event(0x49,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'J'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4A,0,0,0);
               keybd_event(0x4A,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'K'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4B,0,0,0);
               keybd_event(0x4B,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'L'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4C,0,0,0);
               keybd_event(0x4C,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'M'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4D,0,0,0);
               keybd_event(0x4D,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'N'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4E,0,0,0);
               keybd_event(0x4E,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'O'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x4F,0,0,0);
               keybd_event(0x4F,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'P'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x50,0,0,0);
               keybd_event(0x50,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'Q'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x51,0,0,0);
               keybd_event(0x51,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'R'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x52,0,0,0);
               keybd_event(0x52,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'S'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x53,0,0,0);
               keybd_event(0x53,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'T'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x54,0,0,0);
               keybd_event(0x54,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'U'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x55,0,0,0);
               keybd_event(0x55,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'V'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x56,0,0,0);
               keybd_event(0x56,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'W'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x57,0,0,0);
               keybd_event(0x57,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'X'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x58,0,0,0);
               keybd_event(0x58,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'Y'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x59,0,0,0);
               keybd_event(0x59,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case 'Z'://CAPITALS
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x5A,0,0,0);
               keybd_event(0x5A,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case ' '://SPACE==========
               keybd_event(VK_SPACE,0,0,0);
               keybd_event(VK_SPACE,0,KEYEVENTF_KEYUP,0);
               break;
          case '='://equal
               keybd_event(0xBB,0,0,0);
               keybd_event(0xBB,0,KEYEVENTF_KEYUP,0);
               break;
          case ','://comma
               keybd_event(0xBC,0,0,0);
               keybd_event(0xBC,0,KEYEVENTF_KEYUP,0);
               break;
          case '.'://period
               keybd_event(0xBE,0,0,0);
               keybd_event(0xBE,0,KEYEVENTF_KEYUP,0);
               break;
          case '>'://>
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBE,0,0,0);
               keybd_event(0xBE,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '<'://comma================
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBC,0,0,0);
               keybd_event(0xBC,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;//---------------------
          case '0'://SPACE
               keybd_event(0x30,0,0,0);
               keybd_event(0x30,0,KEYEVENTF_KEYUP,0);
               break;
          case '1'://SPACE
               keybd_event(0x31,0,0,0);
               keybd_event(0x31,0,KEYEVENTF_KEYUP,0);
               break;
          case '2'://SPACE
               keybd_event(0x32,0,0,0);
               keybd_event(0x32,0,KEYEVENTF_KEYUP,0);
               break;
          case '3'://SPACE
               keybd_event(0x33,0,0,0);
               keybd_event(0x33,0,KEYEVENTF_KEYUP,0);
               break;
          case '4'://SPACE
               keybd_event(0x34,0,0,0);
               keybd_event(0x34,0,KEYEVENTF_KEYUP,0);
               break;
          case '5'://SPACE
               keybd_event(0x35,0,0,0);
               keybd_event(0x35,0,KEYEVENTF_KEYUP,0);
               break;
          case '6'://SPACE
               keybd_event(0x36,0,0,0);
               keybd_event(0x36,0,KEYEVENTF_KEYUP,0);
               break;
          case '7'://SPACE
               keybd_event(0x37,0,0,0);
               keybd_event(0x37,0,KEYEVENTF_KEYUP,0);
               break;
          case '8'://SPACE
               keybd_event(0x38,0,0,0);
               keybd_event(0x38,0,KEYEVENTF_KEYUP,0);
               break;
          case '9'://SPACE
               keybd_event(0x39,0,0,0);
               keybd_event(0x39,0,KEYEVENTF_KEYUP,0);
               break;
          case ')'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x30,0,0,0);
               keybd_event(0x30,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '!'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x31,0,0,0);
               keybd_event(0x31,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '@'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x32,0,0,0);
               keybd_event(0x32,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '#'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x33,0,0,0);
               keybd_event(0x33,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '$'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x34,0,0,0);
               keybd_event(0x34,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '%'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x35,0,0,0);
               keybd_event(0x35,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '^'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x36,0,0,0);
               keybd_event(0x36,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '&'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x37,0,0,0);
               keybd_event(0x37,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '*'://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x38,0,0,0);
               keybd_event(0x38,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '('://SPACE
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0x39,0,0,0);
               keybd_event(0x39,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '+'://add
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBB,0,0,0);
               keybd_event(0xBB,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '-':// MINUS
               keybd_event(0xBD,0,0,0);
               keybd_event(0xBD,0,KEYEVENTF_KEYUP,0);
               break;
          case '_':// underscore
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBD,0,0,0);
               keybd_event(0xBD,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case ':':// colon
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBA,0,0,0);
               keybd_event(0xBA,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '{':// {
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xDB,0,0,0);
               keybd_event(0xDB,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '[':// [
               keybd_event(0xDB,0,0,0);
               keybd_event(0xDB,0,KEYEVENTF_KEYUP,0);
               break;
          case '}':// }
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xDD,0,0,0);
               keybd_event(0xDD,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case ']':// ]
               keybd_event(0xDD,0,0,0);
               keybd_event(0xDD,0,KEYEVENTF_KEYUP,0);
               break;
          case '?':// ?
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBF,0,0,0);
               keybd_event(0xBF,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '/':// /
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xBF,0,0,0);
               keybd_event(0xBF,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '\"':// "
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xDE,0,0,0);
               keybd_event(0xDE,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '\'':// " '
               keybd_event(0xDE,0,0,0);
               keybd_event(0xDE,0,KEYEVENTF_KEYUP,0);
               break;
          case '|'://  |
               keybd_event(VK_SHIFT,0,0,0);
               keybd_event(0xDC,0,0,0);
               keybd_event(0xDC,0,KEYEVENTF_KEYUP,0);
               keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
               break;
          case '\\'://  \    //
               keybd_event(0xDC,0,0,0);
               keybd_event(0xDC,0,KEYEVENTF_KEYUP,0);
               break;
          default:
               cout<<"how?"<<endl;
     }
}

void auto_type(string type_this){
     size_t string_size = type_this.size();
     for(size_t i=0; i<string_size; ++i)
          virtual_key_press(type_this[i]);
}

#endif // STRING_TO_KEYINPUT_H_INCLUDED
