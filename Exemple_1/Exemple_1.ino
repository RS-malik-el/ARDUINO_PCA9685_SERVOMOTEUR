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
 * Les servomoteurs sont connecté aux cannaux 0 à 2
 * 
 * Les valeurs de l'angle varie de -90 à +90
 * */

#include <PCA9685.h> // Insertion de la bibliothèque

// Objet de type PCA9685 permettant de controler le module
PCA9685 pwmController; 
// Objet de type PCA9685_ServoEval permettant de convertir l'angle en valeur PWM
PCA9685_ServoEval pwmAngleValue;

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
    pwmController.setChannelPWM(0, pwmAngleValue.pwmForAngle(-90));
    pwmController.setChannelPWM(1, pwmAngleValue.pwmForAngle(-90));
    pwmController.setChannelPWM(2, pwmAngleValue.pwmForAngle(-90));
    delay(Attente);
    pwmController.setChannelPWM(0, pwmAngleValue.pwmForAngle(0));
    pwmController.setChannelPWM(1, pwmAngleValue.pwmForAngle(0));
    pwmController.setChannelPWM(2, pwmAngleValue.pwmForAngle(0));
    delay(Attente);
    pwmController.setChannelPWM(0, pwmAngleValue.pwmForAngle(90));
    pwmController.setChannelPWM(1, pwmAngleValue.pwmForAngle(90));
    pwmController.setChannelPWM(2, pwmAngleValue.pwmForAngle(90));
    delay(Attente);
}