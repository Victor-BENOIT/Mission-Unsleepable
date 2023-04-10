/**
 * @file buttons.c
 * @brief Gérer les états des 3 buttons poussoirs
 * @date 03/01/2023
 * @author Maxence Bigot
 */

#include "macro_types.h"
#include "config.h"
#include "Actionneur/Buttons/buttons.h"


//FONCTION QUI ENREGISTRE UN APPUIE SUR LE BOUTON GAUCHE

/**
 * @fn bool_e button_left_press_event(void)
 * @brief Gérer l'appuie simple du bouton gauche
 * @date 03/01/2023
 * @author Maxence Bigot
 * @return bool_e Booléen de l'état
 */
bool_e button_left_press_event(){
	static bool_e previous_left_state = FALSE;
	bool_e current_state;
	bool_e ret;

	current_state = !HAL_GPIO_ReadPin(LEFT_BUTTON_GPIO, LEFT_BUTTON_PIN);
	ret = current_state && !previous_left_state;
	previous_left_state = current_state;

	return ret;
}


//FONCTION QUI ENREGISTRE UN APPUIE SUR LE BOUTON CENTRAL

/**
 * @fn bool_e button_center_press_event(void)
 * @brief Gérer l'appuie simple du bouton central
 * @date 03/01/2023
 * @author Maxence Bigot
 * @return bool_e Booléen de l'état
 */
bool_e button_center_press_event(){
	static bool_e previous_center_state = FALSE;
	bool_e current_state;
	bool_e ret;

	current_state = !HAL_GPIO_ReadPin(CENTER_BUTTON_GPIO, CENTER_BUTTON_PIN);
	ret = current_state && !previous_center_state;
	previous_center_state = current_state;

	return ret;
}


//FONCTION QUI ENREGISTRE UN APPUIE SUR LE BOUTON DROIT

/**
 * @fn button_right_press_event(void)
 * @brief Gérer l'appuie simple du bouton droit
 * @date 03/01/2023
 * @author Maxence Bigot
 * @return bool_e Booléen de l'état
 */
bool_e button_right_press_event(){
	static bool_e previous_right_state = FALSE;
	bool_e current_state;
	bool_e ret;

	current_state = !HAL_GPIO_ReadPin(RIGHT_BUTTON_GPIO, RIGHT_BUTTON_PIN);
	ret = current_state && !previous_right_state;
	previous_right_state = current_state;

	return ret;
}
