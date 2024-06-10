/* 
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /        __________   _________   ___________   __________    _________                             /
   /       /___   ___/  /   _____/  /  _____   /  /  _____   \  /  ______/       \\            //      /
   /          /  /     /  /        /  /    /  /  /  /    /  /  /  /_____        \\             //      /
   /         /  /     /  /        /  /____/  /  /  /___/  /   /  ______/   \\\   \\    []    //   ///  /
   /     ___/  /__   /  /_____   /   ____   /  /   ___   \   /  /_____        \\\\--]]]/\[[[--////     /
   /    /________/  /________/  /__/    /__/  /__/    \__/  /________/         /////--][][--\\\\\      /
   /                                                                         //   //--][][--\\   \\    /
   /   ______________________________________________________________           //    ][][    \\       /
   /                                                                                                   /
   /                                                                                                   /
   /  This program is free software for arduino; you can redistribute it and/or modify.                /
   /  Ce programme pour Arduino est libre et gratuit; vous pouvez le distribuez et/ou le modifier.     /
   /                                                                                                   /
   / Auteurs: Olivier et Louis Perez                                                                   /
   /                                                                                                   /
   / Another codes / Autres codes:                                                                     /
   / https://www.icaremaker.com                                                                        /
   / Mail: ionocraft@hotmail.fr                                                                        /
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
*/


/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const byte ROUGE_PIN = 5;   // Broche LED rouge
const byte JAUNE_PIN = 6;   // Broche LED jaune
const byte VERT_PIN = 7;    // Broche LED vert 

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
//'L' est une constante de type "long"
//'UL' est une constante de type "unsigned long"


/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;
void setup() {
/* Initialise les broches */
pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ROUGE_PIN, OUTPUT);
pinMode(JAUNE_PIN, OUTPUT);
pinMode(VERT_PIN, OUTPUT);

digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
pinMode(ECHO_PIN, INPUT);
}

void loop() {
/* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
digitalWrite(TRIGGER_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN, LOW);

/* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);

/* 3. Calcul la distance à partir du temps mesuré */
float distance_mm = measure / 2.0 * SOUND_SPEED;

if (distance_mm <40)
{
digitalWrite(ROUGE_PIN, HIGH);
} else if(distance_mm<120)
{
digitalWrite(JAUNE_PIN, HIGH);
}
else
{
digitalWrite(VERT_PIN, HIGH);
}
/* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
delay(500);

// Eteindre toutes les LEDs
digitalWrite(ROUGE_PIN, LOW);
digitalWrite(JAUNE_PIN,LOW);
digitalWrite(VERT_PIN, LOW);

}