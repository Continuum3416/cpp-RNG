#include <iostream>
#include <string>
#include "random.h"

// Example usage of the Random class with different seeding methods

namespace test{

void testDrive(int min, int max) {

    auto printRandomNumber = [&](const std::string& label, utils::Random& rng) {
        std::cout << label << ": " << rng.getRandomInt(min, max) << std::endl;
    };

    std::cout << "=== Random Number Generation Test ===" << std::endl;

    // Default constructor: Seed with time 0
    utils::Random rng1;
    printRandomNumber("Default seed (Chrono-seconds)", rng1);

    // Custom seed
    utils::Random rng2(12345);
    printRandomNumber("Custom seed (12345)", rng2);

    // Various seed modes
    std::cout << "\n--- Seed Modes ---" << std::endl;

    utils::Random rng3(utils::Random::SeedMode::TimeBased);
    printRandomNumber("Time-based seed", rng3);

    utils::Random rng4(utils::Random::SeedMode::ChronoSeconds);
    printRandomNumber("Chrono-seconds seed", rng4);

    utils::Random rng5(utils::Random::SeedMode::ChronoMicroseconds);
    printRandomNumber("Chrono-microseconds seed", rng5);

    utils::Random rng6(utils::Random::SeedMode::RandomDevice);
    printRandomNumber("Random device seed", rng6);

    utils::Random rng7(utils::Random::SeedMode::EnvironmentBased);
    printRandomNumber("Environment-based seed", rng7);

    utils::Random rng8(utils::Random::SeedMode::Composite);
    printRandomNumber("Composite seed", rng8);

    // Hash-based seed
    std::cout << "\n--- Hash-Based Seed ---" << std::endl;
    utils::RandomString rngS(utils::Random::SeedMode::EnvironmentBased);
    std::string hashSeed = rngS.generateRandomString();
    utils::Random rng9(hashSeed);
    std::cout << "Hash-based seed ('" << hashSeed << "'): " << rng9.getRandomInt(min, max) << std::endl;

    // Custom seed function
    utils::Random rng10([]() { return 98765; });
    printRandomNumber("Custom seed function (98765)", rng10);

    // Additional seed modes
    std::cout << "\n--- Additional Seed Modes ---" << std::endl;

    std::cout << "Sequential seed before rng11: " << utils::Random::getSequentialSeed() << std::endl;
    utils::Random rng11(utils::Random::SeedMode::Sequential);
    std::cout << "Sequential seed after rng11: " << utils::Random::getSequentialSeed() << std::endl;
    printRandomNumber("Sequential seed", rng11);

    utils::Random rng12(utils::Random::SeedMode::Cryptographic);
    printRandomNumber("Cryptographic seed", rng12);

    std::cout << "\n=== Test Complete ===" << std::endl;
}

}

int main(){
    test::testDrive(1, 100);

    // Run: g++ random.cpp -o random.exe; ./random.exe
    return 0;
}