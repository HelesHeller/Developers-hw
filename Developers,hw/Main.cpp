#include <iostream>
#include <string>

class Developer {
protected:
    std::string name;
    int experience;

public:
    Developer(const std::string& developerName, int developerExperience)
        : name(developerName), experience(developerExperience) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Experience: " << experience << " years\n";
    }
};

class FrontendDeveloper : virtual public Developer {
protected:
    std::string frontendSkill;

public:
    FrontendDeveloper(const std::string& developerName, int developerExperience, const std::string& skill)
        : Developer(developerName, developerExperience), frontendSkill(skill) {}

    void displayInfo() const override {
        Developer::displayInfo();
        std::cout << "Frontend Skill: " << frontendSkill << '\n';
    }
};

class BackendDeveloper : virtual public Developer {
protected:
    std::string backendSkill;

public:
    BackendDeveloper(const std::string& developerName, int developerExperience, const std::string& skill)
        : Developer(developerName, developerExperience), backendSkill(skill) {}

    void displayInfo() const override {
        Developer::displayInfo();
        std::cout << "Backend Skill: " << backendSkill << '\n';
    }
};

class FullStackDeveloper : public FrontendDeveloper, public BackendDeveloper {
public:
    FullStackDeveloper(const std::string& developerName, int developerExperience,
        const std::string& frontend, const std::string& backend)
        : Developer(developerName, developerExperience), FrontendDeveloper(developerName, developerExperience, frontend),
        BackendDeveloper(developerName, developerExperience, backend) {}

    void displayInfo() const override {
        Developer::displayInfo();
        std::cout << "Frontend Skill: " << frontendSkill << '\n';
        std::cout << "Backend Skill: " << backendSkill << '\n';
    }
};

int main() {
    FullStackDeveloper fullStackDev("John Doe", 5, "HTML/CSS", "Java");
    fullStackDev.displayInfo();

    return 0;
}
