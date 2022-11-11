int ajout_utilisateur(char * filename,  )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d\n",p.id,p.couleur,p.x,p.y);
        fclose(f);
        return 1;
    }
    else return 0;
}