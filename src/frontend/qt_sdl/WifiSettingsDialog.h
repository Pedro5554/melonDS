/*
    Copyright 2016-2020 Arisotura

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef WIFISETTINGSDIALOG_H
#define WIFISETTINGSDIALOG_H

#include <QDialog>

namespace Ui { class WifiSettingsDialog; }
class WifiSettingsDialog;

class WifiSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WifiSettingsDialog(QWidget* parent);
    ~WifiSettingsDialog();

    static WifiSettingsDialog* currentDlg;
    static WifiSettingsDialog* openDlg(QWidget* parent)
    {
        if (currentDlg)
        {
            currentDlg->activateWindow();
            return currentDlg;
        }

        currentDlg = new WifiSettingsDialog(parent);
        currentDlg->show();
        return currentDlg;
    }
    static void closeDlg()
    {
        currentDlg = nullptr;
    }

private slots:
    void on_WifiSettingsDialog_accepted();
    void on_WifiSettingsDialog_rejected();

    void on_cbDirectMode_stateChanged(int state);
    void on_cbxDirectAdapter_currentIndexChanged(int sel);

private:
    Ui::WifiSettingsDialog* ui;

    bool haspcap;

    void updateAdapterControls();
};

#endif // WIFISETTINGSDIALOG_H
