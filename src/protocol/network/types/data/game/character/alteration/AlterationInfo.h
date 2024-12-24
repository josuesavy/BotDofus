#ifndef ALTERATIONINFO_H
#define ALTERATIONINFO_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class AlterationInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlterationInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlterationInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlterationInfo(FuncTree tree);
  AlterationInfo();
  bool operator==(const AlterationInfo &compared);

  uint alterationId;
  double creationTime;
  uint expirationType;
  double expirationValue;
  QList<QSharedPointer<ObjectEffect>> effects;

private:
  void _alterationIdFunc(Reader *input);
  void _creationTimeFunc(Reader *input);
  void _expirationTypeFunc(Reader *input);
  void _expirationValueFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // ALTERATIONINFO_H