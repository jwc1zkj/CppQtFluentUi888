#pragma once

#include "FluHNavigationItem.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "../FluUtils/FluUtils.h"
#include <QStyleOption>
#include <QPainter>

class FluHNavigationIconTextItem : public FluHNavigationItem
{
    Q_OBJECT
  public:
    FluHNavigationIconTextItem(QWidget* parent = nullptr);

    FluHNavigationIconTextItem(FluAwesomeType awesomeType, QString text, QWidget* parent = nullptr);

    FluHNavigationIconTextItem(QString text, QWidget* parent = nullptr);

    FluHNavigationIconTextItem(FluHNavigationIconTextItem* item);

    ~FluHNavigationIconTextItem();

    void itemClone(FluHNavigationIconTextItem* item);

    std::vector<FluHNavigationIconTextItem*> getItems()
    {
        return m_items;
    }

    void getAllItems(std::vector<FluHNavigationIconTextItem*>& totalItems);

    std::vector<FluHNavigationIconTextItem*> getAllItems();

    QWidget* getWrapWidget1()
    {
        return m_wrapWidget1;
    }

    QWidget* getWrapWidget2()
    {
        return m_wrapWidget2;
    }

    QPushButton* getIconBtn()
    {
        return m_iconBtn;
    }

    QLabel* getLabel()
    {
        return m_label;
    }

    FluAwesomeType getAwesomeType()
    {
        return m_awesomeType;
    }

    QString getText()
    {
        return m_label->text();
    }

    bool getHideIcon()
    {
        return m_bHideIcon;
    }

    void setHideIcon(bool bHideIcon)
    {
        m_bHideIcon = bHideIcon;
    }

   //bool m_bParentIsFlyIconTextItem;
   // bool m_bParentIsNavigationView;

    bool parentIsFlyIconTextItem()
    {
        return m_bParentIsFlyIconTextItem;
    }

    bool parentIsNavigationView()
    {
        return m_bParentIsNavigationView;
    }

    void setParentIsFlyIconTextItem(bool bParent)
    {
        m_bParentIsFlyIconTextItem = bParent;
    }

    void setParentIsNavigationView(bool bParent)
    {
        m_bParentIsNavigationView = bParent;
    }


    void addItem(FluHNavigationIconTextItem* item);

    int calcItemW1Width();
    int calcItemW2Height(FluHNavigationIconTextItem* item);

    void adjustItemHeight(FluHNavigationIconTextItem* item);

    int getDepth();

    FluHNavigationIconTextItem* getRootItem();

    bool isLeaf()
    {
        return m_items.empty();
    }

    void mouseReleaseEvent(QMouseEvent* event);

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }
  signals:
    void itemClicked();
  public slots:
    void onItemClicked();
    void onThemeChanged();

  protected:
    QWidget* m_wrapWidget1;
    QWidget* m_wrapWidget2;

    QWidget* m_indicator;
    QPushButton* m_iconBtn;
    QLabel* m_label;
    QPushButton* m_arrow;
    QHBoxLayout* m_hLayout1;

    std::vector<FluHNavigationIconTextItem*> m_items;

    QVBoxLayout* m_vMainLayout;
    QVBoxLayout* m_vLayout1;

    FluHNavigationIconTextItem* m_parentItem;
    FluAwesomeType m_awesomeType;

    bool m_bHideIcon;
    bool m_bSelected;

    bool m_bParentIsFlyIconTextItem;
    bool m_bParentIsNavigationView;
};