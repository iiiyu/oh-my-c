#include <gtk/gtk.h> 
static GtkWidget *fixed; 
static GtkWidget *button1; 
static GtkWidget *button2; 
int running = 1;
void our_thread1(GtkWidget *button) 
{ 
    gint x,y,towards; 
    x=40; 
    y=40; 
    towards=1; 
    while (running)
    { 
        g_usleep(100000); //一定要加
        gdk_threads_enter(); //在需要与图形窗口交互的时候加
        gtk_fixed_move(GTK_FIXED(fixed),button,x,y); 
        switch(towards) 
        { 
        case 1: 
            x=x+10; 
            if (x==250) towards=2; 
            break; 
        case 2: 
            y=y+10; 
            if (y==250) towards=3; 
            break; 
        case 3: 
            x=x-10; 
            if (x==40) towards=4; 
            break; 
        case 4: 
            y=y-10; 
            if (y==50) towards=5; 
        } 
        gdk_threads_leave();  //搭配上面的
    } 
} 

void our_thread2(GtkWidget *button) 
{ 
    gint i,j,forward; 
    i=80; 
    j=80; 
    forward=1; 
    while (running) 
    { 
        g_usleep(100000); 
        gdk_threads_enter(); 
        gtk_fixed_move(GTK_FIXED(fixed),button2,i,j); 
        switch(forward) 
        { 
        case 1: 
            i=i+10; 
            if (i==290) forward=2; 
            break; 
        case 2: 
            j=j+10; 
            if (j==250) forward=3; 
            break; 
        case 3: 
            i=i-10; 
            if (i==40) forward=4; 
            break; 
        case 4: 
            j=j-10; 
            if (j==40) forward=5; 
        } 
        gdk_threads_leave(); 
    } 
} 
void on_begin(GtkWidget* button,gpointer data) 
{ 
    gtk_widget_set_sensitive(button,FALSE); 
    g_thread_create(our_thread1,button1,FALSE,NULL); 
    g_thread_create(our_thread2,button2,FALSE,NULL); 
} 
void *run_f(GtkWidget *butt,gpointer data)
{
    running = 0;
}
int main(int argc,char* argv[]) 
{ 
    GtkWidget *window,*view; 
    GtkWidget *vbox,*button,*label;

    if (!g_thread_supported()) 
        g_thread_init(NULL); 

    gdk_threads_init();

    gtk_init(&argc,&argv); 
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_title(GTK_WINDOW(window),"thread apllication"); 
    g_signal_connect(G_OBJECT(window),"delete_event", 
                     G_CALLBACK(gtk_main_quit),NULL); 
    gtk_container_set_border_width(GTK_CONTAINER(window),10); 
    vbox=gtk_vbox_new(FALSE,0); 
    gtk_container_add(GTK_CONTAINER(window),vbox); 
    label=gtk_label_new("Notice! Button is moving"); 
    gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,0); 
    view=gtk_viewport_new(NULL,NULL); 
    gtk_box_pack_start(GTK_BOX(vbox),view,FALSE,FALSE,0); 
    fixed=gtk_fixed_new(); 
    gtk_widget_set_usize(fixed,330,330); 
    gtk_container_add(GTK_CONTAINER(view),fixed); 
    button1=gtk_button_new_with_label("1"); 
    button2=gtk_button_new_with_label("2"); 
    gtk_fixed_put(GTK_FIXED(fixed),button1,10,10); 
    gtk_fixed_put(GTK_FIXED(fixed),button2,40,40); 
 
    button=gtk_button_new_with_label("Start"); 
    gtk_box_pack_start(GTK_BOX(vbox),button,FALSE,FALSE,5); 
    g_signal_connect(G_OBJECT(button),"clicked", 
                     G_CALLBACK(on_begin),NULL);                // call on_begin
    
    GtkWidget *run = gtk_button_new_with_label("stop");
    gtk_box_pack_start(GTK_BOX(vbox),run,FALSE,FALSE,5); 
    g_signal_connect(G_OBJECT(run),"clicked", 
                     G_CALLBACK(run_f),NULL);                // call on_begin

    gtk_widget_show_all(window); 
    gdk_threads_enter(); 
    gtk_main(); 
    gdk_threads_leave(); 
    return FALSE; 
}
