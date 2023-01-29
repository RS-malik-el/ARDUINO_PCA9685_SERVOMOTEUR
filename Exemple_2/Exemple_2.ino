/**
 * e-mail : rachelsysteme@gmail.com
 * gitHub : https://github.com/RS-malik-el
 * Donation : paypal.me/RachelSysteme
 *
 * @AUTEUR : RACHEL SYSTEME / OpenProgramming
 * DATE : 25/01/2023
 * 
 * @Board : Arduino
 * 
 * La bibliothèque est disponible dans le gestionnaire de bibliothèque 
 * de l'IDE arduino, rechercher et installer la bibliothèque suivante :
 * 
 * Bibliothèque utilisé : PCA9685_16-Channel_PWM_Driver_Module_Library
 * 
 * Les servomoteurs sont connecté aux cannaux 0 à 7
 * 
 * Les valeurs de l'angle varie de -90 à +90
 * */

#include <PCA9685.h> // Insertion de la bibliothèque

#define NB_SERVO 8 // Nombre de servomoteur connecté

// Objet de type PCA9685 permettant de controler le module
PCA9685 pwmController; 
// Objet de type PCA9685_ServoEval permettant de convertir l'angle en valeur PWM
PCA9685_ServoEval pwmAngleValue;

int pwmValue[NB_SERVO]; // Tableau contenant les valeurs des angles en signal PWM

// Prototype de la fonction
void updateAngle(int angle); // Mets à jour le tableau int pwmValue[NB_SERVO]

void setup(){
    Wire.begin(); // Initialisation de l'interface I2C
    // Ré-initialisation des PCA9685 sur la ligne I2C 
    pwmController.resetDevices();   
    pwmController.init(); // Initilisation du module 
    // Définit une fréquence f=5OHz soit T=20ms
    // pour les Servomoteurs standard              
    pwmController.setPWMFreqServo();
}

void loop(){
    int Attente = 1500; // Petite pause
    updateAngle(-90);
    pwmController.setChannelsPWM(0, NB_SERVO, pwmValue);
    delay(Attente);
    updateAngle(0);
    pwmController.setChannelsPWM(0, NB_SERVO, pwmValue);
    delay(Attente);
    updateAngle(90);
    pwmController.setChannelsPWM(0, NB_SERVO, pwmValue);
    delay(Attente);
}

void updateAngle(int angle){
    for (int i = 0; i < NB_SERVO; ++i){
        pwmValue[i] = pwmAngleValue.pwmForAngle(angle);
    }
}