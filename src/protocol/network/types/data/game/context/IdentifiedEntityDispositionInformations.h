#ifndef IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H
#define IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/utils/io/type/FuncTree.h"

class IdentifiedEntityDispositionInformations : public EntityDispositionInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentifiedEntityDispositionInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentifiedEntityDispositionInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentifiedEntityDispositionInformations(FuncTree tree);
  IdentifiedEntityDispositionInformations();
  bool operator==(const IdentifiedEntityDispositionInformations &compared);

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H