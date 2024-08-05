#pragma once

#include "Frm_Main.h"
#include <QThread>
#include <algorithm>

class SyncDevicesThread : public QThread
{
	Q_OBJECT

private:
	bool is_exit_;
	std::vector<QString> _comboList;


protected:
	void run() override;
	
	bool containsItem(const std::vector<QString> list, const QString& value);

signals:
	void addID(const QString& id);
signals:
	void removeID(const QString& id);
signals:
	void clearIDs();
signals:
	void send_showNumOfDevices_Lable_Text(const QString& text);
signals:
	void I_Need_Combo();

public slots:
	void getCombo(const std::vector<QString>& list);

public:
	SyncDevicesThread(bool is_exit = false) : is_exit_(is_exit){}
	~SyncDevicesThread();
	void stop();
};