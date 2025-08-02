#include <iostream>
#include "controller.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    double output[1500]{0};

    Controller Controller;

    Controller.simulate(5,1,1.1, 60,20);
    Controller.output(output);

    for (int i = 0; i < 1500; ++i) {
        std::cout << output[i] << std::endl;

    }


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}