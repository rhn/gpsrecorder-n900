#ifndef CONSOLETASK_H
#define CONSOLETASK_H


class ConsoleTask : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleTask(QObject *parent = 0);

signals:

public slots:
    void run(void);
};

#endif // CONSOLETASK_H
