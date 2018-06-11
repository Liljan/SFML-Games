#include "State.h"
#include "StateMachine.h"

void StateMachine::AddState(StateRef state, bool isReplacing)
{
	_isAdding = true;
	_isReplacing = isReplacing;

	_newState = std::move(state);
}

void StateMachine::RemoveState()
{
	_isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (_isRemoving && !_states.empty())
	{
		_states.pop();

		if (_states.empty())
		{
			_states.top()->Resume();
		}

		_isRemoving = false;

		if (_isAdding && !_states.empty())
		{
			if (_isReplacing)
				_states.pop();
			else
				_states.top()->Pause();
		}

		_states.push(std::move(_newState));
		_states.top()->Init();
		_isAdding = false;
	}
}

StateRef & StateMachine::GetActiveState()
{
	return _states.top();
}
