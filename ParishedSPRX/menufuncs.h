#pragma once

// ========================================================================= //
//                          ADF MOD MENU - HEADERS                           //
// ========================================================================= //

// --- Fonctions Joueur ---
void ADF_Joueur_ModeDieu();
void ADF_Joueur_MouvementsExtremes();
void ADF_Joueur_EffacerRecherche();

// --- Fonctions Armes ---
void ADF_Armes_MunitionsMaxEtExplosives();
void ADF_Armes_VehicleGun();

// --- Fonctions Véhicules ---
void ADF_Vehicule_Reparer();
void ADF_Vehicule_DriveByAimEtBoost(float VitesseMax);
void ADF_Vehicule_PeintureRGB();
void ADF_FaireApparaitreVoiture(char* ModeleVoiture);

// --- Fonctions Téléportation ---
void ADF_Teleportation(float x, float y, float z);
void ADF_Lieu_Aeroport();
void ADF_Lieu_MontChiliad();
