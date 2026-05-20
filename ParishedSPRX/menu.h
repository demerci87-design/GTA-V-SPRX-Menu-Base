#pragma once

// ========================================================================= //
//                          ADF MOD MENU - HEADER                            //
// ========================================================================= //

class Menu {
public:
    // Affiche une option simple dans le menu
    static bool Option(const char* text);

    // Initialisation du menu
    static void Init();

    // Affiche le titre en haut du menu
    static void Title(const char* title);

    // Gère le dessin du rectangle du menu
    static void DrawRect(float x, float y, float w, float h, int r, int g, int b, int a);

    // Gère l'affichage du texte
    static void DrawText(const char* text, float x, float y, float size, int r, int g, int b, int a);

    // Déplacement dans le menu
    static void MoveCursor();
    
    // Fermeture du menu
    static void Close();

    // Gestion des inputs manette
    static bool IsKeyPressed(int key);
};
