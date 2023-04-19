export const TRICKS = {
  OOT_LENS: "Fewer Lens Requirements (OoT)",
  OOT_TUNICS: "Fewer Tunic Requirements",
  OOT_HIDDEN_GROTTOS: "Hidden Grottos (OoT) without Stone of Agony",
  OOT_MIDO_SKIP: "Backflip Over Mido",
  OOT_MAN_ON_ROOF: "Man on Roof with Nothing",
  OOT_BLIND_WASTELAND: "Blind Wasteland Crossing",
  OOT_DEKU_SKIP: "Deku Tree B1 Skip",
  OOT_DC_JUMP: "Dodongo's Cavern Upper Adult Jump",
  OOT_FOREST_HOOK: "Forest Temple Garden Vines with Hookshot",
  OOT_HAMMER_WALLS: "Hammer Through Walls",
  OOT_VOLCANO_HOVERS: "Volcano Item with Hover Boots",
  OOT_NIGHT_GS: "Nighttime Gold Skulltulas without Sun's Song",
  OOT_CHILD_DOMAIN: "Enter Child Zora's Domain with Cucco",
  OOT_ADULT_DOMAIN: "Enter Adult Zora's Domain using Hover Boots",
  OOT_WATER_LONGSHOT: "Drain Water Temple using Longshot",
  OOT_SAND_RIVER_NOTHING: "Cross the River of Sand with Nothing",
  OOT_SHADOW_FIRE_ARROW: "Enter Shadow Temple using Fire Arrows",
  OOT_KZ_SKIP: "Skip King Zora as Adult",
  OOT_LOST_WOODS_ADULT_GS: "Lost Woods Adult GS without Bean",
  OOT_WINDMILL_HP_NOTHING: "Windmill HP as Adult with Nothing",
  OOT_LAB_DIVE_NO_GOLD_SCALE: "Laboratory Dive without Gold Scale",
  OOT_LAB_WALL_GS: "Laboratory Wall GS with Jump Slash",
  OOT_PASS_COLLISION: "Pass through Visible One-Way Collisions",
  OOT_DMT_RED_ROCK_GS: "DMT Red Rock Skulls without Hammer",
  OOT_DEAD_HAND_STICKS: "Child Dead Hand without Kokiri Sword",
  MM_LENS: "Fewer Lens Requirements (MM)",
  MM_PALACE_BEAN_SKIP: "Skip Planting Beans in Deku Palace",
  MM_DARMANI_WALL: "Climb Mountain Village Wall Blind",
  MM_NO_SEAHORSE: "Pinnacle Rock without Seahorse",
  MM_ZORA_HALL_HUMAN: "Swim to Zora Hall as Human",
  MM_ICELESS_IKANA: "Climb Ikana Canyon without Ice Arrows",
  MM_ONE_MASK_STONE_TOWER: "Climb Stone Tower with One Mask",
  MM_ISTT_EYEGORE: "Inverted Stone Tower Temple Eyegore Skips",
  MM_SCT_NOTHING: "South Clock Town Chest with Nothing",
  MM_GORON_BOMB_JUMP: "Bomb Jump Fences as Goron",
  MM_BOMBER_SKIP: "Guess Bomber Code",
  MM_CAPTAIN_SKIP: "Guess Oceanside Spider House Code",
  MM_ISTT_ENTRY_JUMP: "Inverted Stone Tower Temple Long Jump to Death Armos",
  MM_SHORT_HOOK_HARD: "Precise Short Hookshot Usage",
  MM_PFI_BOAT_HOOK: "Enter Pirate Fortress Interior using Hookshot from the Boats",
  MM_PALACE_GUARD_SKIP: "Backflip over Deku Palace Guards",
  MM_SHT_FIRELESS: "Complete Snowhead Temple without Fire Arrows",
  MM_KEG_EXPLOSIVES: "Use Powder Kegs as Explosives",
  MM_DOG_RACE_CHEST_NOTHING: "Doggy Racetrack Chest with Nothing",
  MM_MAJORA_LOGIC: "Fight Majora to Reset Time",
  MM_SOUTHERN_SWAMP_SCRUB_HP_GORON: "Southern Swamp Scrub HP as Goron",
  MM_ZORA_HALL_SCRUB_HP_NO_DEKU: "Zora Hall Scrub HP without Deku",
  MM_IKANA_ROOF_PARKOUR: "Jump from Ikana Castle's Roof Interior to Exterior",
  MM_POST_OFFICE_GAME: "Post Office Timing Game without Bunny Hood",
};

export type Tricks = {[k in keyof typeof TRICKS]: boolean};
export type Trick = keyof Tricks;

const DEFAULT_ENABLED_TRICKS = new Set<Trick>(['OOT_NIGHT_GS']);

export const DEFAULT_TRICKS = Object.keys(TRICKS).reduce((tricks, trick) => {
  tricks[trick as Trick] = DEFAULT_ENABLED_TRICKS.has(trick as Trick);
  return tricks;
}, {} as Tricks);
