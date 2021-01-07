#include "CliTerminal.h"

Command::Command(char *command_string, void (*callback)(String))
{
    command_str = command_string;
    _callback = callback;
}
void Command::Execute(String str)
{
    _callback(str);
}
Command::~Command()
{
}

void Cli_Terminal::cli_cal()
{
    if (Serial.available())
    {
        int length = Serial.available();
        if (length > CONSOLE_MAX_LENGTH)
        {
            Serial.println("command is too long !! process terminated...");
            return;
        }
        String command = Serial.readStringUntil((char)10);
        Serial.println(command);
        String processed[2];
        *processed = *TextProcessor(command, processed);
        int SettedCommandCount = sizeof(commands) / sizeof(commands[0]);
        for (int itr = 0; itr < SettedCommandCount; itr++)
        {
#ifdef DEBUG
            Serial.println(itr);
            Serial.println(commands[itr].command_str);
            Serial.println(processed[0] == commands[itr].command_str ? "true" : "false");
#endif
            if (processed[0] == commands[itr].command_str)
            {
                commands[itr].Execute(processed[1]);
                break;
            }
            if (itr == SettedCommandCount - 1)
                Serial.println(processed[0] + ": command not found");
        }
        Serial.flush();
        Serial.print(">");
    }
}

String *Cli_Terminal::TextProcessor(String text, String *result)
{
    int space = text.indexOf(" ");
    result[0] = text; //for No Attribute Command
    if (space > 0)
    {
        result[0] = text.substring(0, space);
        result[1] = text.substring(++space, text.length());
    }

#ifdef DEBUG
    Serial.println(result[0]);
    Serial.println(result[1]);
#endif
    return result;
}