#ifndef BINFILE_H
#define BINFILE_H

#include "src/utils/io/Reader.h"
#include "world/WorldGraph.h"

class BINFile
{
public:
    BINFile(const QString &path);
    ~BINFile();

    const QString &getPath() const;
    const WorldGraph *getWorldGraph() const;

private:
    void getFileContent();

    QString m_path;
    WorldGraph *m_worldGraph;
};

#endif // BINFILE_H
