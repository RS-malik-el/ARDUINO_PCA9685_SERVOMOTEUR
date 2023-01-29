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
int attente = 10; // Petite pause (incrémentation / décrémentation)
int pause = 1500; // Temps d'attente avant chaque transition


void setup(){
    Wire.begin(); // Initialisation de l'interface I2C
    // Ré-initialisation des PCA9685 sur la ligne I2C 
    pwmController.resetDevices();   
    pwmController.init(); // Initilisation du module 
    // Définit une fréquence f=5OHz soit T=20ms
    // pour les Servomoteurs standard              
    pwmController.setPWMFreqServo();
    // Position initiale des servomoteurs (-90)
    for (int i = 0; i < NB_SERVO; ++i){
        pwmValue[i] = pwmAngleValue.pwmForAngle(-90);
    }
    pwmController.setChannelsPWM(0, NB_SERVO, pwmValue);
    delay(pause);
}

void loop(){
    // Sens 1
    for (int channel = 0; channel < NB_SERVO; ++channel){
        for (int angle = -90; angle <= +90 ; ++angle){
            pwmController.setChannelPWM(channel, pwmAngleValue.pwmForAngle(angle));  
            delay(attente);
        }  
    }
    
    delay(pause);
    
    // Sens 2
    for (int channel = (NB_SERVO-1); channel >= 0 ; --channel){
        for (int angle = 90; angle >= -90 ; --angle){
            pwmController.setChannelPWM(channel, pwmAngleValue.pwmForAngle(angle));  
            delay(attente);
        }  
    }

    delay(pause);
}