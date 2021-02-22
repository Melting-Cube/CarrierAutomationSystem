/***************************************************************
 * File: keyboard.cpp
 * Author: cube
 * Purpose: Contains the method implementations for the Keyboard class.
 ***************************************************************/

#include "keyboard.h"
#include <X11/X.h>
#include <cstring>
#include <iostream>
#include <xdo.h>

/***************************************************************
 * Function: pressKey
 * Description: Presses the key that was passed to it.
 ***************************************************************/
void Keyboard :: pressKey(std::string key)
{
   xdo_send_keysequence_window(x, window[0], key.c_str(), key_delay);
   // xdo_enter_text_window(x, CURRENTWINDOW, key.c_str(), key_delay);
   return;
}

/***************************************************************
 * Function: type
 * Description: types the prompt that was sent to it
 ***************************************************************/
void Keyboard :: type(std::string phrase)
{
   xdo_enter_text_window(x, CURRENTWINDOW, phrase.c_str(), key_delay);
   return;
}

/***************************************************************
 * Function: search
 * Description: types the prompt that was sent to it
 ***************************************************************/
Window* Keyboard :: search(std::string phrase)
{
   xdo_search_t search;
   Window *list = NULL;
   unsigned int results;

   // set the memory right not to get memory errors
   memset(&search, 0, sizeof(xdo_search_t));
   search.max_depth = -1;
   search.require = xdo_search::SEARCH_ANY;

   search.searchmask |= SEARCH_NAME;
   search.winname = "Elite - Dangerous";
   xdo_search_windows(x, &search, &list, &results);

   return list;
}

/***************************************************************
 * Function: waitForWindow
 * Description: waits for the window to be focused
 ***************************************************************/
void Keyboard :: waitForWindow()
{
   xdo_wait_for_window_focus(x, window[0], 1);
   return;
}

/***************************************************************
 * Function: focusWindow
 * Description: focuses the window
 ***************************************************************/
void Keyboard :: focusWindow()
{
   xdo_focus_window(x, window[0]);
   return;
}