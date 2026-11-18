<!doctype html>
<html lang="am">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Lula Bingo</title><!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Page title</title>
</head>
<body>
    
</body>
</html>

<style>
:root{--bg:#070b18;--panel:#111a2d;--panel2:#17233b;--blue:#168cff;--cyan:#39d7ff;--text:#f3f7ff;--muted:#9eacc5;--gold:#ffc857;--red:#ff5570}
*{box-sizing:border-box}
body{margin:0;background:radial-gradient(circle at top,#102b52,#070b18 55%);color:var(--text);font-family:Arial,sans-serif}
header{padding:18px 5%;display:flex;justify-content:space-between;align-items:center;border-bottom:1px solid #263958;position:sticky;top:0;background:#080e1deF;z-index:5}
.logo{font-weight:900;font-size:24px;letter-spacing:2px;color:var(--cyan)}
.logo span{color:white}
button,select,input,textarea{font:inherit}
button{border:0;border-radius:10px;padding:11px 16px;background:linear-gradient(135deg,var(--blue),#0754b8);color:white;font-weight:700;cursor:pointer}
button:disabled{opacity:.45;cursor:not-allowed}
.wrap{max-width:1200px;margin:22px auto;padding:0 16px}
.grid{display:grid;grid-template-columns:1.5fr 1fr;gap:18px}
.card{background:linear-gradient(145deg,var(--panel),#0c1425);border:1px solid #243957;border-radius:18px;padding:18px;box-shadow:0 12px 35px #0005;margin-bottom:18px}
h2,h3{margin:0 0 14px}
.muted{color:var(--muted);font-size:13px}
.row{display:flex;gap:10px;align-items:center;flex-wrap:wrap}
.field{width:100%;padding:12px;border-radius:9px;border:1px solid #304664;background:#081224;color:white;margin:5px 0 12px}
label{font-size:13px;color:#c6d5eb}
.stats{display:grid;grid-template-columns:repeat(3,1fr);gap:9px;margin-bottom:14px}
.stat{background:#0a1427;padding:12px;border-radius:12px}
.stat b{display:block;font-size:22px;color:var(--cyan);margin-top:5px}
.drawbox{text-align:center;padding:22px;background:linear-gradient(135deg,#0c2344,#101a32);border-radius:16px}
.called{font-size:54px;font-weight:900;color:var(--gold);text-shadow:0 0 25px #ffc85777;min-height:65px}
.countdown{font-size:24px;color:var(--cyan);font-weight:bold}
.balls{display:flex;gap:7px;flex-wrap:wrap;justify-content:center;margin:15px 0}
.ball{width:38px;height:38px;border-radius:50%;display:grid;place-items:center;background:#20395c;border:1px solid #4b709d;font-weight:bold}
.bingo{display:grid;grid-template-columns:repeat(5,1fr);gap:5px;max-width:340px;margin:10px auto}
.cell{background:#132644;border:1px solid #345174;border-radius:7px;padding:12px 3px;text-align:center;font-weight:bold}
.cell.hit{background:#087cbb;border-color:#5ce6ff;box-shadow:0 0 12px #25cfff66}
.cell.free{color:var(--gold)}
.player{display:flex;align-items:center;gap:10px;padding:9px;border-bottom:1px solid #253650}
.avatar{width:36px;height:36px;border-radius:50%;object-fit:cover;background:#29415f}
.pill{padding:5px 9px;border-radius:20px;background:#143b5f;color:#8be5ff;font-size:12px}
#notice{padding:12px;border-radius:9px;background:#152d49;color:#bcecff;margin:10px 0;display:none;font-weight:bold}
.danger{background:#491d2a!important;color:#ffd4dc!important}
.winner{font-size:26px;color:var(--gold);font-weight:900;text-align:center;padding:15px}
nav{display:flex;gap:8px;flex-wrap:wrap;margin:15px 0}
nav button{background:#1a2a44}
nav button.active{background:var(--blue)}
.hidden{display:none!important}
.money{color:#70e6a0;font-weight:bold}
.small{font-size:12px}
@media(max-width:800px){
.grid{grid-template-columns:1fr}
.stats{grid-template-columns:repeat(3,1fr)}
header{padding:14px}
.called{font-size:42px}
}
</style>
</head>

<body>

<header>
<div class="logo">LULA <span>BINGO</span></div>
<div class="row">
<span id="connection" class="pill">Not connected</span>
<select id="lang" class="field" style="width:auto;margin:0" onchange="setLang(this.value)">
<option value="am">አማርኛ</option>
<option value="en">English</option>
</select>
</div>
</header>

<div class="wrap">

<div id="notice"></div>

<section id="register" class="card">
<h2 data-am="ተጫዋች ምዝገባ" data-en="Player registration">ተጫዋች ምዝገባ</h2>

<p class="muted" data-am="ስም፣ ስልክ ቁጥር እና የፕሮፋይል ፎቶ ያስገቡ።" data-en="Enter your name, phone number and profile photo.">
ስም፣ ስልክ ቁጥር እና የፕሮፋይል ፎቶ ያስገቡ።
</p>

<div class="grid">
<div>
<label>ስልክ ቁጥር / Phone number (09xxxxxxxx)</label>
<input id="phone" class="field" type="tel" inputmode="numeric" maxlength="10" placeholder="09xxxxxxxx">

<label>ስም / Display name</label>
<input id="name" class="field" maxlength="40" placeholder="ስም / Name">

<label>የፕሮፋይል ፎቶ (አማራጭ) / Profile photo</label>
<input id="photo" class="field" type="file" accept="image/*">

<button onclick="createAccount()">ተመዝገብ / Register</button>
</div>

<div>
<h3 data-am="የጨዋታ ደንቦች" data-en="Game rules">የጨዋታ ደንቦች</h3>
<p>• እስከ 100 ተጫዋቾች / Up to 100 players</p>
<p>• ምዝገባ ነፃ ነው። / Registration is free.<br>
• የጨዋታ ክፍሎች: <b>5 ብር</b> እና <b>10 ብር</b></p>
<p>• የአስተዳዳሪ ኮሚሽን: <b>1 ብር</b> ከእያንዳንዱ ተጫዋች</p>
</div>
</div>
</section>

<section id="roomSelect" class="card hidden">
<h2>የጨዋታ ክፍል ምረጥ / Choose a game room</h2>
<p class="muted">ምዝገባ ከጨረሱ በኋላ ከሁለቱ ክፍሎች አንዱን ይምረጡ። / After registration, choose one of the rooms.</p>

<div class="grid">
<div class="card">
<h2>5 ብር</h2>
<p>የ5 ብር ጨዋታ ክፍል / 5 ETB game room</p>
<button onclick="joinRoom('room5')">ወደ 5 ብር ክፍል ግባ / Join 5 ETB room</button>
</div>

<div class="card">
<h2>10 ብር</h2>
<p>የ10 ብር ጨዋታ ክፍል / 10 ETB game room</p>
<button onclick="joinRoom('room10')">ወደ 10 ብር ክፍል ግባ / Join 10 ETB room</button>
</div>
</div>
</section>

<section id="app" class="hidden">

<div class="stats">
<div class="stat">
<span data-am="ተጫዋቾች" data-en="Players">ተጫዋቾች</span>
<b id="playerCount">0/100</b>
</div>

<div class="stat">
<span data-am="የመግቢያ ክፍያ" data-en="Entry fee">የመግቢያ ክፍያ</span>
<b id="entryFee">5 ETB</b>
</div>

<div class="stat">
<span data-am="የእኔ ቀሪ ሂሳብ" data-en="My Balance">የእኔ ቀሪ ሂሳብ</span>
<b id="topBalance" style="color:#70e6a0">0 ETB</b>
</div>
</div>

<nav>
<button class="active" onclick="tab('game',this)" data-am="ጨዋታ" data-en="Game">ጨዋታ</button>
<button onclick="tab('wallet',this)" data-am="ገንዘብ" data-en="Wallet">ገንዘብ</button>
<button onclick="tab('deposit',this)">ገንዘብ አስገባ / Deposit</button>
<button onclick="tab('withdraw',this)">ገንዘብ አውጣ / Withdraw</button>
<button id="agentTab" class="hidden" onclick="tab('agent',this)">Agent</button>
<button onclick="tab('history',this)" data-am="ታሪክ" data-en="History">ታሪክ</button>
<button onclick="tab('settings',this)" data-am="ማስተካከያ" data-en="Settings">ማስተካከያ</button>
</nav>

<div id="game" class="grid">
<div>

<div class="card drawbox">
<h2 data-am="የቢንጎ እጣ ማውጫ" data-en="Bingo number draw">የቢንጎ እጣ ማውጫ</h2>
<div class="called" id="currentCall">READY</div>
<div class="countdown" id="timer">01:00</div>
<p class="muted" id="status">ጨዋታው ለመጀመር ዝግጁ ነው</p>
<p class="money" id="prizeInfo"></p>
<div class="row" style="justify-content:center">
<button id="startBtn" onclick="startGame()">▶ ጀምር / Start</button>
<button id="callBtn" onclick="callNumber()" disabled>ቀጣይ ቁጥር / Next</button>
<button onclick="claimBingo()" style="background:linear-gradient(135deg,#f59e0b,#d97706)">BINGO!</button>
</div>
</div>

<div class="card">
<h3 data-am="የተጠሩ ቁጥሮች" data-en="Called numbers">የተጠሩ ቁጥሮች</h3>
<div id="balls" class="balls"></div>
</div>

<div class="card">
<h3 data-am="የእኔ ካርድ" data-en="My card">የእኔ ካርድ</h3>
<p class="muted">እያንዳንዱ ተጫዋች የራሱን ካርድ ያገኛል፤ እስከ 100 ካርዶች በአንድ ክፍል።</p>
<div id="myCard" class="bingo"></div>
</div>

</div>

<div>
<div class="card">
<h3 data-am="በክፍሉ ያሉ ተጫዋቾች" data-en="Players in room">በክፍሉ ያሉ ተጫዋቾች</h3>
<div id="players"></div>
</div>

<div class="card">
<h3 data-am="አሸናፊ" data-en="Winner">አሸናፊ</h3>
<div id="winner" class="winner">—</div>
<p class="muted">አሸናፊው በራስ-ሰር ለማረጋገጥ BINGO! ይጫን።</p>
</div>
</div>
</div>

<div id="wallet" class="card hidden">
<h2 data-am="የገንዘብ ገቢና ወጪ" data-en="Wallet income and expenses">የገንዘብ ገቢና ወጪ</h2>

<div class="stats">
<div class="stat">ቀሪ ሂሳብ<b id="balance">0 ETB</b></div>
<div class="stat">ጠቅላላ ገቢ<b id="income">0 ETB</b></div>
<div class="stat">ጠቅላላ ወጪ<b id="expense">0 ETB</b></div>
</div>
<p class="muted">በዚህ ሂሳብ በ5 ብርም ሆነ በ10 ብር ክፍል መጫወት ይችላሉ።</p>
</div>

<div id="deposit" class="card hidden">
<h2>ገንዘብ አስገባ / Deposit funds</h2>

<p class="muted">ገንዘቡን ከታች ባሉት አካውንቶች ወደ አንዱ አስገባ፤ ከዚያ የክፍያ ማረጋገጫ ቴክስት ወይም ስክሪንሾት ላክ። አንድ ኤጀንት እስኪያረጋግጥ ድረስ ገንዘቡ Pending ይሆናል።</p>

<div class="card">
<b>Telebirr</b>
<p>0910795916 — abelula</p>

<b>Commercial Bank of Ethiopia</b>
<p>1000169031839 — abelula</p>

<b>CBE Birr</b>
<p>0910795916 — abelula</p>
</div>

<label>የሚያስገቡት ገንዘብ / Amount (ETB)</label>
<input id="depositAmount" class="field" type="number" min="5">

<label>የክፍያ ማስረጃ ቴክስት / Transaction reference or SMS text</label>
<textarea id="depositText" class="field" rows="3"></textarea>

<label>ስክሪንሾት (አማራጭ) / Screenshot (optional)</label>
<input id="depositProof" class="field" type="file" accept="image/*">

<button onclick="submitDeposit()">የገቢ ጥያቄ ላክ / Submit deposit request</button>

<h3>የእኔ የገቢ ጥያቄዎች / My deposit requests</h3>
<div id="myDeposits">—</div>
</div>

<div id="withdraw" class="card hidden">
<h2>ገንዘብ አውጣ / Withdraw funds</h2>
<p class="muted">ያሸነፉትን ገንዘብ ወደ ቴሌብር ወይም ባንክ አካውንትዎ ወጪ ይጠይቁ።</p>

<label>የመክፈያ መንገድ / Payment Method</label>
<select id="withdrawMethod" class="field">
<option value="Telebirr">Telebirr</option>
<option value="CBE">Commercial Bank of Ethiopia (CBE)</option>
<option value="CBE Birr">CBE Birr</option>
</select>

<label>አካውንት ቁጥር ወይም ስልክ / Account or Phone Number</label>
<input id="withdrawAccount" class="field" placeholder="09xxxxxxxx ወይም 1000xxxxxxxx"><div></div>

<label>የአካውንቱ ባለቤት ስም / Account Holder Name</label>
<input id="withdrawAccountName" class="field" placeholder="ሙሉ ስም / Full Name">

<label>የሚያወጡት ገንዘብ / Amount (ETB)</label>
<input id="withdrawAmount" class="field" type="number" min="10">

<button onclick="submitWithdraw()">የወጪ ጥያቄ ላክ / Request Withdrawal</button>

<h3>የእኔ የወጪ ጥያቄዎች / My withdrawal requests</h3>
<div id="myWithdrawals">—</div>
</div>

<div id="agent" class="card hidden">
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Page title</title>
</head>
<body>
    
</body>
</html>### አንድ የመጨረሻ ወሳኝ ማሳሰቢያ (Firebase Indexes)፦ የገቢ (`deposits`) እና የወጪ (`withdrawals`) ዝርዝሮች በፍጥነት እንዲሰሩና Firebase ማስጠንቀቂያ እንዳያሳይህ፣ በFirebase Console ውስጥ **Realtime Database -> Rules** ገብተህ ይህንን አስቀምጥ፦ ```json { "rules": { ".read": "auth != null", ".write": "auth != null", "deposits": { ".indexOn": ["uid", "status"] }, "withdrawals": { ".indexOn": ["uid", "status"] } } } 

