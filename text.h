class Text {

public:

    sf::Font font;
    sf::Text text;

    void initText(std::string TEXT, int FONT_SIZE, std::string FONT) {

        if (!font.loadFromFile(FONT)) {

            error("Failed to Load Font");

        }

        text.setFont(font);
        text.setString("Hello world");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Regular);

    }

};