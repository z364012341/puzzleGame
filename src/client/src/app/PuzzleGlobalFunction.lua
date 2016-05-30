cc.exports.GlobalFunction = {
	createGameSpriteWithPath = function (path)
		return cc.Sprite:create(path);
		--return cc.Sprite:createWithSpriteFrameName(path);
	end,
	copyGameSprite = function (sprite)
		local sp = cc.Sprite:createWithTexture(sprite:getTexture());
		return sp;
	end,
	setGameSpriteTextureWithPath = function (path, sprite)
		sprite:setTexture(path);
		--local frame = cc.SpriteFrameCache:getInstance():getSpriteFrameByName(path);
        --sprite:setSpriteFrame(frame);
	end,
	getPuzzlePiecePositionWithDirection = function (direction)
		return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_POSITION];
	end,
	getPuzzlePiecePositionWithRotation = function (direction, insideOrOutside)
		--assert(direction and insideOrOutside);
	    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
	        return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_ROTATION]+180;
	    else
	        return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_ROTATION];
	    end
	end,
	getVisibleCenterPosition = function ()
		local size = cc.Director:getInstance():getVisibleSize();
		return	cc.p(size.width*0.5, size.height*0.5);
	end,
	createCustomEvent = function ( name, userData )
	    local event = cc.EventCustom:new(name);
	    event._userData = userData;
	    return event;
	end,
	getCustomEventUserData = function ( event )
		return event._userData;
	end,
	calculateMinSizeScale = function ( size_1, size_2 )
		return math.min(size_1.width/size_2.width, size_1.height/size_2.height);
	end
}
