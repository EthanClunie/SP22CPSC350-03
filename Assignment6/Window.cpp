/**
 * @file Window.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Implementation file for Window class. Contains function implementations to 
 * create a Window as well as access/manipulate its idle time information
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Window.h"


/**
 * @brief Construct a new Window:: Window object
 * 
 */
Window::Window()
{
    totalIdleTime = 0;
}


/**
 * @brief Destroy the Window:: Window object
 * 
 */
Window::~Window()
{
}


/**
 * IncrementWindowIdleTime
 * @brief Increments the idle time of a window by 1
 * 
 */
void Window::IncrementWindowIdleTime()
{
    this->totalIdleTime += 1;
}


/**
 * GetWindowIdleTime
 * @brief Returns the totalIdleTime value of the window this is called on
 * 
 * @return int 
 */
int Window::GetWindowIdleTime()
{
    return this->totalIdleTime;
}