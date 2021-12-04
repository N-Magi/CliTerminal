# CliTerminal
## Description
Simple Serial Terminal library
## usage
 * Install Liblary
 * define ` Cli_Terminal terminal(100); `
 * define Call Back Mehod (ex ` terminal.commands[0] = Command("retValue", [](String str) -> void { Serial.println("Lamda " + str); }); `
 * and add `terminal.cli_cal()` in ` void loop() `
