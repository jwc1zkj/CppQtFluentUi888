#pragma once

#include "FluAEmptyPage.h"
#include "../FluUtils/FluUtils.h"
#include "../FluControls/FluSpinBox.h"
#include "../FluControls/FluDoubleSpinBox.h"
#include "../FluControls/FluDisplayBox.h"
#include "../FluControls/FluVScrollView.h"

class FluNumberBoxPage : public FluAEmptyPage
{
    Q_OBJECT
  public:
    FluNumberBoxPage(QWidget* parent = nullptr) : FluAEmptyPage(parent)
    {
        m_mainLayout->setAlignment(Qt::AlignTop);
        m_titleLabel->setText("NumberBox");

        m_infoLabel->setText("Use NumberBox to allow users to enter a algebraic equations and numeric input in your app.");

        addSpinBox();

        addDoubleSpinBox();

        FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluNumberBoxPage.qss", this);
    }

    void addSpinBox()
    {
        auto displayBox = new FluDisplayBox;
        displayBox->setTitle("A spin box");
        displayBox->getCodeExpander()->setCodeByPath("../code/NumberBoxPageCode1.md");
        displayBox->setBodyWidgetFixedHeight(90);

        auto spinBox = new FluSpinBox(this);
        spinBox->setFixedWidth(150);
        displayBox->getBodyLayout()->addWidget(spinBox);
        m_vScrollView->getMainLayout()->addWidget(displayBox, 0, Qt::AlignTop);
    }

    void addDoubleSpinBox()
    {
        auto displayBox = new FluDisplayBox;
        displayBox->setTitle("A double spin box");
        displayBox->getCodeExpander()->setCodeByPath("../code/NumberBoxPageCode2.md");
        displayBox->setBodyWidgetFixedHeight(90);

        auto doubleSpinBox = new FluDoubleSpinBox(this);
        doubleSpinBox->setFixedWidth(150);
        displayBox->getBodyLayout()->addWidget(doubleSpinBox);
        m_vScrollView->getMainLayout()->addWidget(displayBox, 0, Qt::AlignTop);
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluNumberBoxPage.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluNumberBoxPage.qss", this);
        }
    }
};
