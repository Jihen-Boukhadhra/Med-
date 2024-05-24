#include "fichier.h"
int saisir()
{ int x;
    printf("saisir le nombre de patients ") ;
    scanf("%d",&x) ;
    return x;}
int saisir1()
{ int x;
    printf("\n saisir le nombre des dossier medicaux ") ;
    scanf("%d",&x) ;
    return x;}
MED * AllocationMedicaments(int n)
{MED* medicament ;
    medicament=(MED*) malloc (n * sizeof (MED));
    if(!medicament) exit(-4);
    return medicament ;}
void RemplirMedicament (MED * medicaments, int s)
{ for (int k = 0; k < s ; k++)
    { printf("\n saisir les infos du medicament %d ", k+ 1);
        printf("\n saisir la reference du medicament\n");
        scanf("%d", &(medicaments + k)->reference);
        printf("\n saisir le nom du medicament\n");
        scanf("%s", &(medicaments + k)->nom_medicament); }}
void AfficherMedicament(MED medicaments)
{   printf("\n la reference du medicament est %d" ,medicaments.reference);
      printf("\n le nom du medicament est %s" , medicaments.nom_medicament );}
void SaisirVisite(VISITE * visites, int j)
{printf("\n saisir les visites %d ",j+1);
      printf("\n saisir la date du rendez-vous %d ",j+1);
      scanf("%d%d%d", &visites->date_RDV.jour,&visites->date_RDV.mois, &visites->date_RDV.annee);
      printf("\n saisir le nombre de medicaments\n");
      scanf("%d", &visites->nbr_medicaments);
      printf("\n saisir les medicaments\n");
      visites->medicaments=AllocationMedicaments(visites->nbr_medicaments);
      RemplirMedicament(visites->medicaments,visites->nbr_medicaments);}
void AfficherVisite(VISITE visites)
{printf("\n----------\n");
printf("\n la date du rendez-vous est %d /%d /%d " ,visites.date_RDV.jour,visites.date_RDV.mois,visites.date_RDV.annee);
printf("\n le nombre de medicaments est %d " ,visites.nbr_medicaments );
printf("\n voici ses medicaments\n");
for(int k=0; k< visites.nbr_medicaments; k++){AfficherMedicament(*(visites.medicaments+k)); }}
VISITE * AllocationVisite(int n)
{ VISITE * visites ;
    visites=(VISITE*) malloc (n * sizeof (VISITE));
    if(!visites) exit(-3);
    return visites ;
}
void RemplirTabVisites(VISITE *  visites , int m )
{
  printf("Remplissage du Tableau de Visites");
  for(int j=0; j<m; j++)
      {
         SaisirVisite(visites+j,j);
       }
}
DOSSIER ** AllocationDossier(int m)
{DOSSIER **d;
   d=(DOSSIER**) malloc (m*sizeof(DOSSIER*));
   if(!d) exit(-1);
   return d;
}
void RemplirTabDossierMedical(DOSSIER ** d,int n)
{for(int l=0;l<n;l++)
    {
        printf("\n saisir l'identifiant de patient ");
        scanf("%d",&(*(d+l))->idPatient);
        printf("\n saisir l'etat sanitaire ");
        scanf("%s",&(*(d+l))->etat_sanitaire); }}
void AfficherTabDossierMedical(DOSSIER**d,int m)
{for(int l=0;l<m;l++)
    {printf("\n l'identifiant de patient est %d",(*(d+l))->idPatient);
        printf("\n l'etat sanitaire est %s",(*(d+l))->etat_sanitaire);
    }}
void SaisirPatient(PATIENT*p)
{printf("\n saisir le nom et le prenom ");
        scanf("%s", &p->nom_prenom);
        printf("\n saisir le sexe du patient ");
        scanf("%s", &p->sexe);
        printf("\n saisir la profession ");
        scanf("%s", &p->profession);
        printf("\n saisir la date de naissance ");
        scanf("%d%d%d", &p->date_naiss.jour,&p->date_naiss.mois,&p->date_naiss.annee);
        printf("\n saisir son age ");
        scanf("%d", &p->age);
        printf("\n saisir son numero de telephone ");
        scanf("%d", &p->num_telephone);
        printf("\n saisir le nombre de visites ");
        scanf("%d", &p->nbr_visites);
        p->visites=AllocationVisite(p->nbr_visites);
        RemplirTabVisites(p->visites,p->nbr_visites);
}
void AfficherPatient(PATIENT p,int i)
{printf("\n les infos du patient %d ", i+1);
    printf("\n le nom complet du patient est %s " ,p.nom_prenom );
    printf("\n le sexe du patient est %s", p.sexe);
    printf("\n la profession est %s ", p.profession);
    printf("\n la date de naissance est %d/%d/%d" ,(p.date_naiss).jour,(p.date_naiss).mois,(p.date_naiss).annee );
    printf("\n son age est %d" ,p.age);
    printf("\n son numero de telephone est %d ",p.num_telephone);
    printf("\n le nombre de visites est %d" ,p.nbr_visites);
    printf("\n les visites du patient " );
    for(int j=0; j< p.nbr_visites;j++)
      AfficherVisite(*(p.visites+j));}
PATIENT * AllocationPatient(int n)
{ PATIENT * p;
    p=(PATIENT*) malloc (n * sizeof (PATIENT));
    if(!p) exit(-2);
    return p ;}
void RemplirTabPatients(PATIENT* p , int n)
{printf("Remplissage Tableau de Patients");
    for(int i=0; i<n; i++)
    {SaisirPatient(p+i);}}
void AfficherTabPatients(PATIENT* p,int n )
{ for(int i=0; i<n;i++)
    AfficherPatient(*(p+i),i);}
float RecetteMensuelle(PATIENT *p,int n)
{ int m,a;
    printf("saisir le mois et l'annee desires :");
    scanf("%d%d",&m,&a);
    int R=0;
    for (int i=1; i<32;i++)
    {DATE dat;
        dat.jour=i;
        dat.mois=m;
        dat.annee=a;
        R+=RecetteJournaliere(p,dat,n); }
    return R;}
float RecetteJournaliere(PATIENT*p,DATE date,int n)
{ int nb;
    nb=NbrePatient(p,date,n);
    return nb*70;}
int NbrePatient(PATIENT*p,DATE date,int n)
{ int nb;
    nb=0;
    for(int i=0;i<n;i++)
    { for(int j=0;j< p[i].nbr_visites;j++)
        {if ((( p[i].visites[j].date_RDV.jour)==date.jour )&&(( p[i].visites[j].date_RDV.mois)==date.mois)
                &&(( p[i].visites[j].date_RDV.annee)==date.annee))
              nb++; } }  return nb ;}
int MaxNbreVisites(PATIENT*p,int n)
 {int max;
    max=1;
    for(int i=0;i<n;i++)
    {if (p[i].nbr_visites > max)
            max=p[i].nbr_visites;} return max;}
void PatientPlusVisite(PATIENT*p,int n)
{int nb;
    nb=MaxNbreVisites(p,n);
    for(int i=0;i<n;i++) {if ((p+i)->nbr_visites==nb)
            printf(" le patient le plus visite est d'indice %d ",i+1) ; }}
