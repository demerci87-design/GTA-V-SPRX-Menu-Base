#include "menu.h"
#include "menufuncs.h"

// Le "Main" est maintenant intégré ici pour simplifier le projet
void Main() {
    while (true) {
        CheckMenu();
        GAMEPLAY::WAIT(0);
    }
}

// Fonction qui lit tes boutons
void CheckMenu() {
    // ========================================================================= //
    //                          ADF MOD MENU - LES BOUTONS                       //
    // ========================================================================= //

    if (Menu::Option("Mode Dieu Invincible")) { ADF_Joueur_ModeDieu(); }
    if (Menu::Option("Mouvements Extremes")) { ADF_Joueur_MouvementsExtremes(); }
    if (Menu::Option("Effacer Recherche Police")) { ADF_Joueur_EffacerRecherche(); }

    if (Menu::Option("Balles Explosives & Munitions Max")) { ADF_Armes_MunitionsMaxEtExplosives(); }
    if (Menu::Option("Tirer des Voitures")) { ADF_Armes_VehicleGun(); }

    if (Menu::Option("Reparer le Vehicule")) { ADF_Vehicule_Reparer(); }
    if (Menu::Option("Peinture RGB Auto")) { ADF_Vehicule_PeintureRGB(); }
    if (Menu::Option("Boost Vitesse 350 km/h (Maintiens CROIX)")) { ADF_Vehicule_DriveByAimEtBoost(97.0f); }
    if (Menu::Option("Boost Vitesse 600 km/h (Maintiens CROIX)")) { ADF_Vehicule_DriveByAimEtBoost(166.0f); }

    if (Menu::Option("Faire apparaitre : Ferrari")) { ADF_FaireApparaitreVoiture("turismor"); }
    if (Menu::Option("Faire apparaitre : Lamborghini")) { ADF_FaireApparaitreVoiture("zentorno"); }
    if (Menu::Option("Faire apparaitre : Mercedes AMG")) { ADF_FaireApparaitreVoiture("schafter2"); }
    if (Menu::Option("Faire apparaitre : BMW")) { ADF_FaireApparaitreVoiture("sentinel"); }
    if (Menu::Option("Faire apparaitre : Range Rover")) { ADF_FaireApparaitreVoiture("baller"); }

    if (Menu::Option("Teleportation : Aeroport")) { ADF_Lieu_Aeroport(); }
    if (Menu::Option("Teleportation : Mont Chiliad")) { ADF_Lieu_MontChiliad(); }
}
