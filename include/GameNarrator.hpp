#pragma once

#include "space_alerte.hpp"

class GameNarrator {
private:
    bool voiceEnabled;
    std::string voiceName;
    int speechSpeed;
    int speechPitch;
    
public:
    GameNarrator() {};
    GameNarrator(bool enabled = true, const std::string& voice = "fr", 
                 int speed = 150, int pitch = 50) 
        : voiceEnabled(enabled), voiceName(voice), 
          speechSpeed(speed), speechPitch(pitch) {}
    
    void speak(const std::string& text) {
        if (!voiceEnabled) return;
        
        std::string command = "espeak -v " + voiceName + 
                             " -s " + std::to_string(speechSpeed) + 
                             " -p " + std::to_string(speechPitch) + 
                             " \"" + text + "\"";
        system(command.c_str()); // replique la commande: system("espeak -v en -s 150 \"Hello World\"");
    }
    
    void announce(const std::string& message) {
        std::cout << message << std::endl;
        speak(message);
    }
    
    // Pour les moments dramatiques de Space Alert !
    void announceUrgent(const std::string& message) {
        std::cout << "🚨 " << message << " 🚨" << std::endl;
        // Voix plus rapide et aiguë pour l'urgence
        std::string command = "espeak -v " + voiceName + 
                             " -s " + std::to_string(speechSpeed + 50) + 
                             " -p " + std::to_string(speechPitch + 20) + 
                             " \"" + message + "\"";
        system(command.c_str());
    }
    ~GameNarrator() {};
};