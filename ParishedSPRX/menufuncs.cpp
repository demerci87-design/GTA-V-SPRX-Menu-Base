#include "menufuncs.h"


void EnterMenu(int menuId) {
	self->BackgroundShader->ScaleOverTime(0.25f, 400, 90 + (self->MaxScroll[MainMenu] * 25));
	for (int i = 0; i < self->MaxScroll[self->CurrentMenu]; i++) {
		//self->Options[i] = CreateText(menu[self->CurrentMenu][i].text, self->screen.width - 390, 140 + (25 * i), 0.45f, 0, color_s(0, 0, 0, 0), ALIGN_BOTTOM, ALIGN_LEFT);
		self->Options[i]->FadeOverTime(0.45f, color_s(0, 0, 0, 0));
		self->Options[i]->Free();


		if (menu[self->CurrentMenu][i].isSlider) {
			self->SliderOpts[i]->FadeOverTime(0.45f, color_s(0, 0, 0, 0));
			self->SliderOpts[i]->Free();
		}

	}

	self->CurrentOption = 0;
	self->CurrentMenu = menuId;

	for (int i = 0; i < self->MaxScroll[menuId]; i++) {
		self->Options[i] = CreateText(menu[menuId][i].text, (self->screen.width / 2) - 150, 140 + (25 * i), 0.45f, 0, color_s(0, 0, 0, 0), ALIGN_CENTER, ALIGN_LEFT);
		self->Options[i]->FadeOverTime(0.45f, color_s(255, 255, 255, 255));

		if (menu[self->CurrentMenu][i].isSlider) {
			self->SliderOpts[i] = CreateText(menu[MainMenu][i].sliderText, (self->screen.width / 2) + 150, 140 + (25 * i), 0.45f, 0, color_s(0, 0, 0, 0), ALIGN_CENTER, ALIGN_RIGHT);
			self->SliderOpts[i]->FadeOverTime(0.45f, color_s(255, 255, 255, 255));
		}

	}

	self->CreatorText->text = menu[menuId][0].title;

	self->ScrollbarShader->MoveOverTime(0.25f, self->ScrollbarShader->x, 153.0f + (self->CurrentOption * 25));
}// ========================================================================= //
//                          ADF MOD MENU - LE MOTEUR                         //
// ========================================================================= //

void ADF_Joueur_ModeDieu() {
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (MonPed != 0) {
        ENTITY::SET_ENTITY_INVINCIBLE(MonPed, true);
        PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true); 
    }
}

void ADF_Joueur_MouvementsExtremes() {
    GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
    PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.5f);
}

void ADF_Joueur_EffacerRecherche() {
    PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
    PLAYER::SET_MAX_WANTED_LEVEL(0);
}

void ADF_Armes_MunitionsMaxEtExplosives() {
    int MonPed = PLAYER::PLAYER_PED_ID();
    GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
    unsigned int ArmeActuelle;
    if (WEAPON::GET_CURRENT_PED_WEAPON(MonPed, &ArmeActuelle, true)) {
        WEAPON::SET_AMMO_IN_CLIP(MonPed, ArmeActuelle, 999);
    }
}

void ADF_Armes_VehicleGun() {
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_SHOOTING(MonPed)) {
        Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(MonPed, 0.0, 5.0, 0.0);
        uint hash = GAMEPLAY::GET_HASH_KEY("t20"); 
        if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash)) {
            STREAMING::REQUEST_MODEL(hash);
            while (!STREAMING::HAS_MODEL_LOADED(hash)) GAMEPLAY::WAIT(0);
            VEHICLE::CREATE_VEHICLE(hash, coords.x, coords.y, coords.z, ENTITY::GET_ENTITY_HEADING(MonPed), true, false);
            STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
        }
    }
}

void ADF_Vehicule_Reparer() {
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(MonPed, false)) {
        VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_IN(MonPed, false));
    }
}

void ADF_Vehicule_DriveByAimEtBoost(float VitesseMax) {
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(MonPed, false)) {
        int MonVehicule = PED::GET_VEHICLE_PED_IS_IN(MonPed, false);
        PLAYER::SET_PLAYER_TARGETING_MODE(3); 
        if (CONTROLS::IS_CONTROL_PRESSED(0, 73)) { 
            VEHICLE::SET_VEHICLE_FORWARD_SPEED(MonVehicule, VitesseMax);
            GAMEPLAY::SET_TIME_SCALE(ENTITY::IS_ENTITY_IN_AIR(MonVehicule) ? 0.2f : 1.0f);
        } else {
            GAMEPLAY::SET_TIME_SCALE(1.0f);
        }
    }
}

void ADF_Vehicule_PeintureRGB() {
    static int rgb_tick = 0; 
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(MonPed, false)) {
        int MonVehicule = PED::GET_VEHICLE_PED_IS_IN(MonPed, false);
        rgb_tick += 5;
        if (rgb_tick > 255) rgb_tick = 0;
        VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(MonVehicule, rgb_tick, 255 - rgb_tick, 150);
        VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(MonVehicule, 255 - rgb_tick, rgb_tick, 150);
    }
}

void ADF_Teleportation(float x, float y, float z) {
    int MonPed = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(MonPed, false)) {
        ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(MonPed, false), x, y, z, 1, 0, 0, 1);
    } else {
        ENTITY::SET_ENTITY_COORDS(MonPed, x, y, z, 1, 0, 0, 1);
    }
}

void ADF_Lieu_Aeroport() { ADF_Teleportation(-1336.0f, -3044.0f, 13.9f); }
void ADF_Lieu_MontChiliad() { ADF_Teleportation(501.7f, 5595.2f, 796.2f); }

void ADF_FaireApparaitreVoiture(char* ModeleVoiture) {
    uint hash = GAMEPLAY::GET_HASH_KEY(ModeleVoiture);
    if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash)) {
        STREAMING::REQUEST_MODEL(hash);
        while (!STREAMING::HAS_MODEL_LOADED(hash)) GAMEPLAY::WAIT(0);
        int MonPed = PLAYER::PLAYER_PED_ID();
        Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(MonPed, 0.0, 5.0, 0.0);
        int MonVehicule = VEHICLE::CREATE_VEHICLE(hash, coords.x, coords.y, coords.z, ENTITY::GET_ENTITY_HEADING(MonPed), true, false);
        PED::SET_PED_INTO_VEHICLE(MonPed, MonVehicule, -1); 
        STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
    }
}
