#include <iostream>

enum State { IDLE, RUNNING, ERROR };

class SystemStateMachine {
public:
    SystemStateMachine() : state(IDLE) {}

    void handleEvent(int event) {
        switch (state) {
            case IDLE:
                if (event == 1) {
                    state = RUNNING;
                    std::cout << "Transition: IDLE -> RUNNING" << std::endl;
                }
                break;
            case RUNNING:
                if (event == 2) {
                    state = ERROR;
                    std::cout << "Transition: RUNNING -> ERROR" << std::endl;
                }
                break;
            case ERROR:
                if (event == 0) {
                    state = IDLE;
                    std::cout << "Transition: ERROR -> IDLE" << std::endl;
                }
                break;
        }
    }

private:
    State state;
};

int main() {
    SystemStateMachine sm;
    sm.handleEvent(1);
    sm.handleEvent(2);
    sm.handleEvent(0);
    return 0;
}
