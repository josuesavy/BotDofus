#ifndef RANKMINIMALINFORMATION_H
#define RANKMINIMALINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class RankMinimalInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RankMinimalInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RankMinimalInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RankMinimalInformation(FuncTree tree);
  RankMinimalInformation();
  bool operator==(const RankMinimalInformation &compared);

  uint id;
  QString name;

private:
  void _idFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // RANKMINIMALINFORMATION_H