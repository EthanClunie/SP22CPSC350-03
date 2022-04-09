/**
 * @file Window.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file with definitions of a Window object and its idle time information
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WINDOW_H
#define WINDOW_H

class Window
{
    public:
        Window();
        ~Window();

        void IncrementWindowIdleTime();
        int GetWindowIdleTime();

    private:
        int totalIdleTime;

};

#endif