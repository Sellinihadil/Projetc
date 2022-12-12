//change the GtkButton to GtkWidget 
//or wrap the button in GTK_WIDGET(button)
on_btn_clicked(GtkWidget *object , ...)



//basic widget variable setup
GtkWidget *widget1,widget2....;
widget1 = lookup_widget(objet , "widgetName")

/*
    spin button 
*/
//--get value
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget1));
//set value
gtk_spin_button_set_value(widget,"value");

/* 
    combobox
*/

//--add element
gtk_combo_box_append_text(GTK_COMBO_BOX(widget) , "text here");
//--get active element
gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget))

/*
    label
*/

//--set text
gtk_label_set_text(GTK_LABEL(widget))

/*
    text entry
*/ 

//get_text
gtk_entry_get_text(GTK_ENTRY(widget))
//set text
gtk_entry_set_text(GTK_ENTRY(widget))

/*
    radio button and checkbox
*/

//get values (checkbox)

void on_box1_toggled (gtkToggleButton *toggleButton ...)
if(gtk_toggle_button_get_active(togglebutton)){
    choix[i] = 1
}

void res(... , char output[]){
    if()...
    else if()....
    else if()...
}
//get values (radiobutton)
on_radiobutton_toggled (GtkToggleButton *toggleBtn,...){
    if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(toggleBtn))){
        choix = i
    }
}

//set active
 gtk_toggle_button_set_active(GTK_RADIO_BUTTON(toggleBtn1),TRUE);

/*
    show hide window
*/
 
GtkWidget *fenetre_1;
GtkWidget *fenetre_2;
fenetre_1 = lookup_widget(button, "fenetre_1");
gtk_widget_hide (fenetre_1);
fenetre_2 = create_fenetre_2 ();
gtk_widget_show (fenetre_2);
