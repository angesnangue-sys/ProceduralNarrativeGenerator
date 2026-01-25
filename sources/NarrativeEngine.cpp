#include "includes/NarrativeEngine.h"
#include "includes/Story.h"
#include "includes/Character.h"
#include "includes/Theme.h"
#include "includes/ThemeData.h"

#include <cstdlib>
#include <ctime>

//fonction utilitaire pour choisir un element aleatoire
static std::string pickRandom(const std::vector<std::string>& v)
{
    return v[rand() % v.size()];
}

std::string NarrativeEngine::generateStory(Theme theme) 
{
    srand(static_cast<unsigned>(time(nullptr)));

    ThemeData data;
    //chargement des donnees selon le theme

    if (theme == Theme::FEERIQUE)
    {
        data.names = {
            "Luna",
            "Eliora",
            "Faen"
        };

        data.locations = {
            "la foret sacree",
            "l'arbre des fees",
            "le lac enchante"
        };

        data.weapons = {
            "baguette magique",
            "poussiere de fee",
            "baton lumineux"
        };

        data.events = {
            "un esprit ancien se reveilla",
            "une ombre corrompue apparut",
            "un sort interdit fut brise"
        };

        data.introTemplates = {
            "{NAME} vivait paisiblement a {LOCATION}.",
            "{NAME}, armee de sa {WEAPON}, explorait {LOCATION}."
        };

        data.eventTemplates = {
            "un jour, {EVENT}."
            "{NAME} utilisa sa {WEAPON} pour faire face au danger.",
            "le chaos s'etendit dans {LOCATION}."
        };

        data.conclusionTemplates = {
            "finalement, {NAME} retablit l'equilibre.",
            "{NAME} quitta {LOCATION}, trandformee par cette aventure."
        };
    }

    //creation du personnage
        Character c;
        c.name = pickRandom(data.names);
        c.location = pickRandom(data.locations);
        c.weapon = pickRandom(data.weapons);
        c.theme = theme;

        Story story;

    //fonction de remplacement des mot-cles
    auto replace = [&](std::string text)
    {
        size_t pos;
        if ((pos = text.find("{NAME}")) != std::string::npos)
        text.replace(pos, 6, c.name);

        if ((pos = text.find("{LOCATION}")) != std::string::npos)
        text.replace(pos, 10, c.location);

        if ((pos = text.find("{WEAPON}")) != std::string::npos)
        text.replace(pos, 8, c.weapon);

        return text;
    };

    //introduction
    story.paragraphs.push_back(replace(pickRandom(data.introTemplates)));

    //peripeties
    for (int i = 0; i <= 3; ++i)
    {
        story.paragraphs.push_back(replace(pickRandom(data.eventTemplates)));
    }

    //conclusion
    story.paragraphs.push_back(replace(pickRandom(data.conclusionTemplates)));

    return story.toString();
}
