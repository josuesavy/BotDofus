#ifndef GUILDRANKMINIMALINFORMATION_H
#define GUILDRANKMINIMALINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRankMinimalInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRankMinimalInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRankMinimalInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRankMinimalInformation(FuncTree tree);
  GuildRankMinimalInformation();
  bool operator==(const GuildRankMinimalInformation &compared);

  uint id;
  QString name;

private:
  void _idFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // GUILDRANKMINIMALINFORMATION_H