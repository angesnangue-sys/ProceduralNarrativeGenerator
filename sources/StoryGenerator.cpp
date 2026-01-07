#include "StoryGenerator.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

StoryGenerator::StoryGenerator() {
    srand(static_cast<unsigned>(time(nullptr)));
    loadDefaultCharacter();
}

// Fonction pour choisir un élément aléatoire d'un vecteur
template<typename T>
const T& StoryGenerator::pickRandom(const std::vector<T>& list) const {
    return list[rand() % list.size()];
}

// Charger les personnages et leurs phrases
void StoryGenerator::loadDefaultCharacter() {
    Character loulu;
    loulu.name = "Le petit chiot Loulu";
    loulu.introduction = {
        "C etait une nuit pluvieuse et Loulu avait ete abandonne sur la rue.",
        "Loulu tremblait sous la pluie, seul et affame.",
        "Personne ne savait d'ou venait ce petit chiot."
    };
    loulu.actions = {
        "il courait à travers les flaques d'eau",
        "Il renifla chaque coin de la rue à la recherche d'un abri",
        "il suivait le son des pas pour trouver quelqu'un"
    };
    loulu.obstacles = {
        "helas, Un gros chien grogna et Loulu dut se cacher",
        "soudainement, La pluie redoubla et Loulu eut du mal a avancer",
        "soudain, Un portail ferme bloqua son chemin"
    };
    loulu.conclusion = {
        "Finalement, Loulu trouva une maison accueillante.",
        "Loulu se blottit dans un panier chaud et s'endormit.",
        "Une famille gentille découvrit Loulu et l'adopta."
    };

    Character marie;
    marie.name = "Marie";
    marie.introduction = {
        "Marie marchait lentement dans la foret sombre.",
        "C etait un matin calme et Marie se preparait a une nouvelle aventure.",
        "Marie observait le ciel en se demandant ce que la journee lui reservait."
    };
    marie.actions = {
        "elle ramassa une branche tombee",
        "Elle traversa le petit pont au-dessus de la riviere",
        "elle s'arreta pour ecouter le chant des oiseaux"
    };
    marie.obstacles = {
        "soudain, Un vent violent fit tomber les feuilles autour d'elle",
        "soudain, Marie trebucha sur une racine et se releva rapidement",
        "soudain, Un nuage noir cachait soudain le soleil"
        "soudain, un jeune homme l'intercepta pour lui precher l'evangile. "
    };
    marie.conclusion = {
        "Finalement, Marie arriva saine et sauve chez elle.",
        "Marie sourit en contemplant le paysage autour d'elle.",
        "Marie termina sa journee en paix, satisfaite de ses decouvertes."
        "Marie finit par recevoir Jesus coe son Seigneur et son sauveur.v"
    };

    personnages.push_back(loulu);
    personnages.push_back(marie);
}

// Générer une histoire structurée pour un personnage
std::string StoryGenerator::Generateparagraph() {

    const Character& c = pickRandom(personnages);
    std::string story;

    story += pickRandom(c.introduction) + "\n";

    story += pickRandom(c.actions) + "\n";

    story += pickRandom(c.obstacles) + "\n";

    story += pickRandom(c.conclusion) + "\n";

    saveToFile(story);
    return story;
}

// Sauvegarder l'histoire dans un fichier
void StoryGenerator::saveToFile(const std::string& text) {
    std::ofstream file("generated_stories.txt", std::ios::app);
    if (file) {
        file << text << "\n\n";
        file.close();
    }
}
 