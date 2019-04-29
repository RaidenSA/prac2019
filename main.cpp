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

void draw(void*)
{
	int end;
    while((end = gui.country->step())){
        if(gui.is_ended == false){
            gui.buttonEnd->show();
        }
        //Output stats
        char data[1024];
		int ill = gui.country->getIll();
    	int healthy = gui.country->getHealthy();
    	int coffers = gui.country->stock.getCoffers();
    	int vaccinated = gui.country->cities[0].well.getAlreadyVaccinated();
    	sprintf(data, "ill: %d\nhealthy: %d\ncoffers: %d\nvaccinated:%d\n",
			ill, healthy, coffers, vaccinated);
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
  int tax = atoi(gui.inputs[3]->value());
  gui.inputs[3]->hide();
  int allowance = atoi(gui.inputs[4]->value());
  gui.inputs[4]->hide();
  int vacCost = atoi(gui.inputs[5]->value());
  gui.inputs[5]->hide();
	gui.country = new Country(cityCounter, fundSize, mounth, tax, allowance,vacCost);
	Fl::add_timeout(0.5, draw);
}

void callbackStop(Fl_Widget *w, void* data)
{
    gui.buttonEnd->hide();
    gui.is_ended = true;
}

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
  output = new Fl_Multiline_Output(210, 0, 260, 140, "Country stats");
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
  input = new Fl_Input(start_w, start_h, size_w, size_h, "mounth period");
  input->value("5");
  inputs.push_back(input);
  start_h += size_h;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "tax rate");
  input->value("1");
  inputs.push_back(input);
  start_h += size_h;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "allowance rate");
  input->value("3");
  inputs.push_back(input);
  start_h += size_h;
  input = new Fl_Input(start_w, start_h, size_w, size_h, "vaccination cost");
  input->value("2");
  inputs.push_back(input);
  window->end();
  window->show();
  return Fl::run();
}

int main()
{
	return gui.start();
}
