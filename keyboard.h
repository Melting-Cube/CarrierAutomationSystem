/***************************************************************
 * File: keyboard.h
 * Author: cube
 * Purpose: class to simplify keystrokes
 ***************************************************************/
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
extern "C" {
    #include <xdo.h>
}

class Keyboard
{
  private:
    xdo_t * x;
    useconds_t key_delay;
    Window *window;

    Window* search(std::string phrase);

  public:
    Keyboard()
    {
        x = xdo_new(0);
        key_delay = 200000;
        window = search("Elite - Dangerous");
    }
    Keyboard(std::string window)
    {
        x = xdo_new(0);
        key_delay = 200000;
        this->window = search(window);
    }

    void pressKey(std::string key);
    void type(std::string phrase);
    void waitForWindow();
    void focusWindow();

};

#endif