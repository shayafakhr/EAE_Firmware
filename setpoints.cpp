int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <setpoint>" << std::endl;
        return 1;
    }

    double setpoint = atof(argv[1]);
    std::cout << "Using setpoint: " << setpoint << std::endl;
}
