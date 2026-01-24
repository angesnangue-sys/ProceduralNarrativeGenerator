#include "NarrativeEngine.h"
#include <cstdlib>
#include <ctime>

NarrativeEngine::NarrativeEngine() {
    srand(static_cast<unsigned>(time(nullptr)));

    ThemeData fairy;

    fairy.names = {
        "la foret sacree",
        "l'arbre des fees",
        "le lac enchante"
    };

    fairy.weapons = {
        "baguette magique",
        "poussiere de fee",
        "baton lumineux"
    };

    fairy.events = {
        "un esprit ancien se reveilla",
        "une ombre corrompue apparut",
        "un sort interdit fut brise"
    };

    fairy.introTemplates = {
        "{NAME} vivait paisiblement a {LOCATION}.",
        "{NAME}, armee de sa {WEAPON}, explorait {LOCATION}."
    };

    fairy.eventTemplates = {
        "un jour, {EVENT}."
        "{NAME} utilisa sa {WEAPON} pour faire face au danger.",
        "le chaos s'etendit dans {LOCATION}."
    };

    fairy.conclusionTemplates = {
        "finalement, {NAME} retablit l'equilibre.",
        "{NAME} quitta {LOCATION}, trandformee par cette aventure."
    };

    database[Theme::FEERIQUE] = fairy;
}

const std::string& NarrativeEngine::randomFrom(const std::vector<std::string>& v) {
    return v[rand() % v.size()];
}

Character NarrativeEngine::createCharacter(theme theme) {
    ThemeData& data = database[theme];

    Character c;
    c.theme = theme;
    c.name = randomFrom(data.names);
    c.location = randomFrom(data.loctaions);
    c.weapon = randomFrom(data.weapons);

    return c;
}

std::string NarrativeEngine::applyTemplate(
    std::string tpl,
    const Character& c,
    const std::string& event
) {
    auto replace = [&](const std::string& key, const std::string& value){
        size_t pos;
        while ((pos = tpl.find(key)) != std::string::npos) {
            tpl.replace(pos, key.length(), value);
        }
    };

    replace("{NAME}", c.name);
    replace("{LOCATION}", c.location);
    replace("{WEAPON}", c.weapon);
    replace{"{EVENT}", event};

    return tpl;
}

Story NarrativeEngine::generateStory(Theme theme){
    Story story;
    ThemeData& data = database[theme];

    Character c = createCharacter(theme);
    
    story.paragraphs.push_back(
        applyTemplate(randomFrom(data.introTemplates), c, "")
    );

    for (int i = 0; i < 3; i++) {
        story.paragraphs.push_back(applyTemplate(
            randomFrom(data.eventTemplates),
            c,
            randomFrom(data.events)
        )
    );
    }

    story.paragraphs.push_back(
        applyTemplate(randomFrom(data.conclusionTemplates), c, "")
    );

    return story;
}