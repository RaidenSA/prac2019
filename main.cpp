#include "virusSaurin.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Multiline_Output.H>
#include <Fl/Fl_Input.H>

class Gui{
public:
    vector<Fl_Input*> inputs;
    Fl_Multiline_Output* output;
    Fl_Button* buttonStart;
    Fl_Button* buttonEnd;
    Country* country;
    bool is_ended;
    int start(); 
}gui;

int Gui::start()
{ 
  int w = 640; 
  int h = 480; 
  int size_w = 50;
  int size_h = 30;
  int start_w = w-size_w;
  int start_h = 0;
  is_ended = false; 
  Fl_Window *window = new Fl_Window(w, h);
  buttonStart = new Fl_Button(210, 100, 220, 100, "start simulation");
  buttonStart->type(FL_NORMAL_BUTTON);
  buttonStart->labelsize(30);
  buttonStart->callback(callbackStart, NULL);
  buttonEnd = new Fl_Button(210, 300, 220, 100, "end simulation");
  buttonEnd->type(FL_NORMAL_BUTTON);
  buttonEnd->labelsize(30);
  buttonEnd->callback(callbackStop, NULL);
  buttonEnd->hide();
  output = new Fl_Multiline_Output(210, 0, 220, 140, "stats");
  output->hide();
  output->textsize(30);
  output->value("");
  Fl_Input* input;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "city counter");
  input->value("1");
  inputs.push_back(input);
  start_h += size_h;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "fund size");
  input->value("1000");
  inputs.push_back(input);
  start_h += size_h;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "mounth");
  input->value("5");
  inputs.push_back(input);
  window->end();
  window->show();
  return Fl::run();
}


void callbackStart(Fl_Widget *w, void* data)
{
    gui.buttonStart->hide();
    srand(time(NULL));
    int i = 0;
    int cityCounter = atoi(gui.inputs[0]->value());
    gui.inputs[0]->hide();
    int fundSize = atoi(gui.inputs[1]->value());
    gui.inputs[1]->hide();
    int mounth = atoi(gui.inputs[2]->value())*4;
	gui.inputs[2]->hide();
	gui.country = new Country(cityCounter, fundSize, mounth);
	Fl::add_timeout(0.5, draw);
}

void callbackStop(Fl_Widget *w, void* data)
{
    gui.buttonEnd->hide();
    gui.is_ended = true;
}

void draw(void*)
{
	int end;
    while((end = gui->country.step())){
        if(gui.is_ended == false){
            gui.buttonEnd->show();
        }
        //Output stats
        char data[1024];
    	int health = rus.getHealthy();
    	int sick = (rus.cities[0].well.healthy - rus.cities[0].well.vaccinated[2])/5;
    	int vaccinated = rus.cities[0].well.vaccinated[2];
    	sprintf(data, "ill: %d\nhealthy: %d\nsick: %d\nvaccinated:%d\n",
			ill, healthy, sick, vaccinated);
        gui.output->value(data);
        gui.output->show();
        if(gui.is_ended == false){
            break;
        }
    }
	if(end == 0){
		gui.is_ended = true;
		gui.buttonEnd->hide();
	}
    Fl::repeat_timeout(0.5, draw);
}


int main()
{
	return gui.start();
}
