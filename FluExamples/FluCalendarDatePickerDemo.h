#pragma once

#include "../FluControls/FluCalendarDatePicker.h"

class FluCalendarDatePickerDemo : public QWidget
{
	Q_OBJECT
  public:
	  FluCalendarDatePickerDemo(QWidget* parent = nullptr) : QWidget(parent)
	  {
              FluCalendarDatePicker* picker = new FluCalendarDatePicker(this);
              picker->move(50, 50);

			  resize(600, 400);
	  }
};
