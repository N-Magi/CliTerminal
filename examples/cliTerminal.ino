#include <CliTerminal.h>
//#include "../CliTerminal.h"

//Set Method limit to 10 pcs
//default is 50
#define METHOD_PCS 10

//Define. 50 is Console Charactor maximum Length 
Cli_Terminal terminal(50);

//method prototype
void method(Sting str);

void setup()
{
    //Setting Command Array by Lamda expression
    //First attribute is Command 
    //Second Attribute is Method pointer
    //`str` has Command Attribute forexample, Enter command "lamda abc" str is "abc" or Enter Command "lamda -r abc" str is "-r abc".
    terminal.commands[0] = Command("lamda", [](String str) -> void { Serial.println("Lamda " + str); });
    //or this
    terminal.commands[1] = Command("method", method);

    //You Need Start Serial with what you like baudrate this sample use 115200bps
    Serial.begin(115200);
    Serial.print(">");
}

void loop()
{
    //terminal Need Call
    terminal.cli_cal();    
}
void method(String str)
{

}
