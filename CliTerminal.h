/*
  CliTerminal.h - Library for Arduino Terminal(Console) System
  Created By N_Magi January 8 2021
  Released into the public domain.
*/
#ifndef CLITERMINAL_h
#define CLITERMINAL_h

#ifdef METHOD_PCS
#else
#define METHOD_PCS 50
#endif

#include <Arduino.h>

//#define CONSOLE_MAX_LENGTH 50

class Command
{
private:
    void (*_callback)(String);

public:
    char *command_str;
    Command(char *command_string, void (*callback)(String));
    Command(){};
    void Execute(String str);
    ~Command();
};

class Cli_Terminal
{
private:
    String *TextProcessor(String text, String *result);
    int CONSOLE_MAX_LENGTH;
    
public:
    Cli_Terminal(int maxLength) { CONSOLE_MAX_LENGTH = maxLength;};
    Command commands[METHOD_PCS];
    void cli_cal();
    ~Cli_Terminal(){};
};

#endif
