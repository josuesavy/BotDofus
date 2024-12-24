#ifndef ABSTRACTSOCIALGROUPINFOS_H
#define ABSTRACTSOCIALGROUPINFOS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class AbstractSocialGroupInfos : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractSocialGroupInfos(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractSocialGroupInfos(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractSocialGroupInfos(FuncTree tree);
  AbstractSocialGroupInfos();
  bool operator==(const AbstractSocialGroupInfos &compared);
};

#endif // ABSTRACTSOCIALGROUPINFOS_H