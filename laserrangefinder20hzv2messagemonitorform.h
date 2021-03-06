/*
    laserrangefinder20hzv2messagemonitorform.h (part of GNSS-Stylus)
    Copyright (C) 2019 Pasi Nuutinmaki (gnssstylist<at>sci<dot>fi)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/**
 * @file laserrangefinder20hzv2messagemonitorform.h
 * @brief Declaration for a form that shows some data about messages sent by "20hz high Accuracy 80m Laser Sensor Range finder Distance measuring module".
 */

#ifndef LASERRANGEFINDER20HZV2MESSAGEMONITORFORM_H
#define LASERRANGEFINDER20HZV2MESSAGEMONITORFORM_H

#include <QWidget>
#include "laserrangefinder20hzv2serialthread.h"

namespace Ui {
class LaserRangeFinder20HzV2MessageMonitorForm;
}

/**
 * @brief Form used to show some data about messages sent by u-blox-devices.
 */
class LaserRangeFinder20HzV2MessageMonitorForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent Parent widget
     * @param title Form title
     */
    explicit LaserRangeFinder20HzV2MessageMonitorForm(QWidget *parent = nullptr, const QString& title = "Message monitor");
    ~LaserRangeFinder20HzV2MessageMonitorForm();

    /**
     * @brief Connects slots from LaserRangeFinder20HzV2SerialThread
     * @param serThread SerialThread to connect signals from
     */
    void connectSerialThreadSlots(LaserRangeFinder20HzV2SerialThread* serThread);

    /**
     * @brief Disconnects slots from SerialThread
     * @param serThread SerialThread to disconnect signals from
     */
    void disconnectSerialThreadSlots(LaserRangeFinder20HzV2SerialThread* serThread);

private:
    Ui::LaserRangeFinder20HzV2MessageMonitorForm *ui;

    void addLogLine(const QString& line);
    QString getTimeDifferenceString(const qint64 startTime, const qint64 endTime);
    void updateStartAndEndTimes(const qint64 startTime, const qint64 endTime);

    qint64 lastStartTime = 0;
    qint64 lastEndTime = 0;

private slots:
    void errorMessage(const QString& errorMessage);
    void warningMessage(const QString& warningMessage);
    void infoMessage(const QString& infoMessage);

    void distanceReceived(const double& distance, qint64 startTime, qint64 endTime);
    void errorReceived(const QString& errorString, qint64 startTime, qint64 endTime);
    void unidentifiedDataReceived(const QByteArray& data, qint64 startTime, qint64 endTime);

    void on_pushButton_ClearAll_clicked();
};

#endif // LASERRANGEFINDER20HZV2MESSAGEMONITORFORM_H
