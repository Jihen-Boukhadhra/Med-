#include <stdio.h>
#include <stdlib.h>

// ********* Structures ********* //

struct DossierMedical
{
    int idPatient;
    char etat_sanitaire[50];
};
typedef struct DossierMedical DOSSIER;

struct Date
{
  int jour;
  int mois;
  int annee;
};
typedef struct Date DATE;

struct Medicament
{
  int reference;
  char nom_medicament[20];
};
typedef struct Medicament MED;

struct Visite
{
  DATE date_RDV;
  int nbr_medicaments;
  MED * medicaments;
};
typedef struct Visite VISITE;

struct Patient
 {
  char nom_prenom[20];
  char sexe[20];
  int age;
  char profession[20];
  int num_telephone;
  DATE date_naiss;
  int nbr_visites;
  VISITE * visites;
};
typedef struct Patient PATIENT;

// ********* Saisie des Entiers ********* //
int saisir();
// Permet de saisir le nombre des patients
int saisir1();
// Permet de saisir le nombre des dossiers médicaux

// ********* Tableau des Dossiers ***********//
DOSSIER ** AllocationDossier(int);
// Permet d'allouer le tableau dynamique d'adresse de structure :Tableau des dossiers médicaux
void RemplirTabDossierMedical(DOSSIER **,int);
// Permet de remplir le tableau des dossiers
void AfficherTabDossierMedical(DOSSIER **,int );
// Permet d'afficher le tableau des dossiers
// ********* Tableau des Médicaments ********* //
MED * AllocationMedicament(int);
// Permet d'allouer le tableau des médicaments pour une visite
void RemplirMedicament(MED *, int);
// Permet de remplir les infos d'un médicament
void AfficherMedicament(MED);
// Permet d'afficher un médicament

// ********* Tableau des visites ********* //
void SaisirVisite(VISITE * ,int);
// Permet de saisir les infos d'une visite
void AfficherVisite(VISITE);
// Permet d'afficher les infos d'une visite
VISITE* AllocationVisite(int);
// Permet d'allouer le tableau des visites pour un patient
void RemplirTabVisites(VISITE *, int);
// Permet de remplir le tableau des visites pour un patient
void AfficherTabVisites(VISITE *, int);
// Permet d'afficher le tableau des visites pour un patient

// ********* Tableau des Patients ********* //
void SaisirPatient(PATIENT *);
// Permet de saisir les informations d'un patient
void AfficherPatient(PATIENT,int );
// Permet d'afficher les infos d'un patient
PATIENT* AllocationPatient(int);
// Permet d'allouer le tableau des patients
void RemplirTabPatients(PATIENT *, int);
// Permet de remplir le tableau des patients
void AfficherTabPatients(PATIENT *, int);
// Permet d'afficher le tableau complet des patients
// ********* Fonctions des Traitements ********* //
int MaxNbreVisites(PATIENT*,int );
// Fonction qui retourne le max de nbre de visites de tous les patients.
void PatientPlusViste(PATIENT*,int);
// Fonction qui retourne le nom de patient le plus visité, cette fonction appelle MaxNbreVisites.
int NbrePatient(PATIENT*,DATE,int);
// Fonction qui retourne le nbre de patients de la journée de date jj/mm/aaaa.
float RecetteJournaliere(PATIENT*,DATE,int);
// Fonction qui retourne la recette d'une journée donnée sachant que le frais de consultation est 70 DT
// cette fonction appelle la fonction NbrePatient.
float RecetteMensuelle (PATIENT *,int);
// Fonction qui retourne la recette mensuelle, cette fonction appelle la fonction RecetteJournaliere.
