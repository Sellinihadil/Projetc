#include "election.h"
#include <stdbool.h>

int ajouterElection(char * filename, Election e )
{
    
    FILE * f=fopen(filename, "a");
    if(f==NULL) return 0;
    
    int id = getNextId(filename);

    bool found = false;
    int i = 0;
    

    fprintf(f,
        "%d %d/%d/%d %d %d %s\n",

        id,
        e.date.year,
        e.date.month,
        e.date.day,
        e.municipality.nbr_councilers,
        e.municipality.nbr_habitants , 
        e.municipality.name
    );
    fclose(f);
    return 1;
}


int modifierElection( char * filename, int id, Election nouv )
{
    int tr=0;
    Election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL) return 0;
    
    while(fscanf(f,
        "%d %d/%d/%d %d %d %s",

        &e.id,
        &e.date.year,
        &e.date.month,
        &e.date.day,
        &e.municipality.nbr_councilers,
        &e.municipality.nbr_habitants , 
        e.municipality.name
        )!=EOF)
    {
        if(e.id== id)
        {
            fprintf(f2,"%d %d/%d/%d %d %d %s\n",
                id,
                nouv.date.year,
                nouv.date.month,
                nouv.date.day,
                nouv.municipality.nbr_councilers,
                nouv.municipality.nbr_habitants ,
                nouv.municipality.name
            );
                    
            tr=1;
        }
        else
            fprintf(
                f2,"%d %d/%d/%d %d %d %s\n",

                e.id,
                e.date.year,
                e.date.month,
                e.date.day,
                e.municipality.nbr_councilers,
                e.municipality.nbr_habitants , 
                e.municipality.name
            );
    }
    
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerElection(char * filename, int id)
{
    int tr=0;
    Election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL) return 0;
    
    while(fscanf(f,
        "%d %d/%d/%d %d %d %s",
        &e.id,
        &e.date.year,
        &e.date.month,
        &e.date.day,
        &e.municipality.nbr_councilers,
        &e.municipality.nbr_habitants ,
        e.municipality.name
    )!=EOF){

        if(e.id== id) tr=1;
        else fprintf(f2,
            "%d %d/%d/%d %d %d %s\n",            

            e.id,
            e.date.year,
            e.date.month,
            e.date.day,                
            e.municipality.nbr_councilers,
            e.municipality.nbr_habitants ,
            e.municipality.name);
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


Election chercherElection(char * filename, int id)
{
    Election e;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,
        
            "%d %d/%d/%d %d %d %s",
            
            &e.id,
            &e.date.year,
            &e.date.month,
            &e.date.day,
            &e.municipality.nbr_councilers,
            &e.municipality.nbr_habitants ,
            e.municipality.name
        )!=EOF)
        {
            if(e.id== id)
            {
                fclose(f);
                return e;
            }
                
        }
    }

    e.id=-1;
    return e; 
    

}

Municipality findMunicipality(char *file , char*name , int *index){
    FILE *fp = fopen(file,"r");
    Municipality m = {0,0,"not found"};
    if(fp == NULL) return m;
    index = 0;
    while(fscanf(fp,
        "%s %d %d",
        m.name,
        &m.nbr_habitants,
        &m.nbr_councilers
    )!=EOF){

        index++;

        if(strcmp(m.name,name) == 0) return m;
    }

    strcpy(m.name,"not found");
    return m;
    fclose(fp);
}

int getNextId(char *filename)
{
  // count the number of lines in the file called filename                                    
    FILE *fp = fopen(filename,"r");
    int newId = 1;

    Election e;

    if (fp == NULL){
        return 0;
    }

    while(fscanf(fp,
        
        "%d %d/%d/%d %d %d %s",
        
        &e.id,
        &e.date.year,
        &e.date.month,
        &e.date.day,
        &e.municipality.nbr_councilers,
        &e.municipality.nbr_habitants ,
        e.municipality.name
    )!=EOF){
        newId = e.id + 1;
    }

    fclose(fp);
    return newId;

  /* int ch=0;
  int lines=0;

  if (fp == NULL){
    return 0;
  }

  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
        lines++;
    } 
  fclose(fp);
  return lines+1;*/
}

int getMuniciplityCount(char *file){
    FILE *fp = fopen(file,"r");
    if(fp == NULL) return -1;

    Municipality m;
    int count = 0;
    while(fscanf(fp,
        "%s %d %d",
        m.name,
        &m.nbr_habitants,
        &m.nbr_councilers
    )!=EOF){
        count++;
    }

    fclose(fp);
    return count;
}

void getMunicipalities(char *file , Municipality *municipalities){
    FILE *fp = fopen(file,"r");
    if(fp == NULL) return;

    Municipality m;
    int i = 0;
    while(fscanf(fp,
        "%s %d %d",
        m.name,
        &m.nbr_habitants,
        &m.nbr_councilers
    )!=EOF){
        municipalities[i] = m;
        i++;
    }

    fclose(fp);
}

enum {
    ID,
    DATE,
    MUNICIPALITY,
    NBR_HABITANTS,
    NBR_COUNCILLORS,
    COLUMNS
};

//show election in tree view given the election id desired
void showElection(GtkWidget *list , int elId){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;

    GtkListStore *store;

    store = NULL;

    char id[10];
    char date[20];
    char municipality[20];
    char  nbr_habitants[20];
    char nbr_councillors[10];

    store = gtk_tree_view_get_model(GTK_TREE_VIEW(list));


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID" , renderer , "text" , ID , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date" , renderer , "text" , DATE , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Municipalité" , renderer , "text" , MUNICIPALITY , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° habitants" , renderer , "text" , NBR_HABITANTS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° councillors" , renderer , "text" , NBR_COUNCILLORS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    }
        store = gtk_list_store_new(COLUMNS , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING);

        FILE *f = fopen("elections.txt","a+");


        if(f == NULL) return;
        char idStr[20];

        sprintf(idStr , "%d" , elId);

        while(fscanf(f , "%s %s %s %s %s\n" , 
            id , 
            date , 
            nbr_councillors ,
            nbr_habitants, 
            municipality 
        )!=EOF){
            if(strcmp(id , idStr)==0)break;
        }
        fclose(f);
        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,ID,id,DATE,date,MUNICIPALITY,municipality,NBR_HABITANTS,nbr_habitants,NBR_COUNCILLORS,nbr_councillors , -1);
        gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
        g_object_unref(store);
    
    
}

void showElections(GtkWidget *list){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;

    GtkListStore *store;

    store = NULL;

    char id[10];
    char date[20];
    char municipality[20];
    char  nbr_habitants[20];
    char nbr_councillors[10];

    store = gtk_tree_view_get_model(GTK_TREE_VIEW(list));


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID" , renderer , "text" , ID , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date" , renderer , "text" , DATE , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Municipalité" , renderer , "text" , MUNICIPALITY , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° habitants" , renderer , "text" , NBR_HABITANTS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° councillors" , renderer , "text" , NBR_COUNCILLORS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    }
        store = gtk_list_store_new(COLUMNS , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING);

        FILE *f = fopen("elections.txt","a+");

        if(f == NULL) return;

        while(fscanf(f , "%s %s %s %s %s\n" , 
            id , 
            date , 
            nbr_councillors ,
            nbr_habitants, 
            municipality 
        )!=EOF){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,ID,id,DATE,date,MUNICIPALITY,municipality,NBR_HABITANTS,nbr_habitants,NBR_COUNCILLORS,nbr_councillors , -1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
        g_object_unref(store);
    
    
}

void emptyListView(GtkWidget *list){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;

    GtkListStore *store;

    store = NULL;

    char id[10];
    char date[10];
    char municipality[20];
    char  nbr_habitants[20];
    char nbr_councillors[10];

    store = gtk_tree_view_get_model(GTK_TREE_VIEW(list));

    if(store == NULL){

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID" , renderer , "text" , ID , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date" , renderer , "text" , DATE , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Municipalité" , renderer , "text" , MUNICIPALITY , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° habitants" , renderer , "text" , NBR_HABITANTS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("n° conseillers" , renderer , "text" , NBR_COUNCILLORS , NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    }
    
    store = gtk_list_store_new(COLUMNS , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING);
    gtk_list_store_append(store,&iter);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);

}


