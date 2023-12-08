// import * as THREE from 'three';
import * as THREE from 'https://cdn.jsdelivr.net/npm/three@0.117.1/build/three.module.js';
import { OrbitControls } from 'https://cdn.jsdelivr.net/npm/three@0.117.1/examples/jsm/controls/OrbitControls.js';

// Set up scene
const scene = new THREE.Scene();

// Set up camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.z = 5;

// Set up renderer
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Load starfield texture
const starfieldTexture = new THREE.TextureLoader().load('textures/starfield.jpg');

// Create cube with starfield texture for the background
const cubeGeometry = new THREE.BoxGeometry(100, 100, 100);
const cubeMaterial = new THREE.MeshBasicMaterial({ map: starfieldTexture, side: THREE.BackSide });
const starfieldCube = new THREE.Mesh(cubeGeometry, cubeMaterial);
scene.add(starfieldCube);

// Load texture for Earth
const earthTexture = new THREE.TextureLoader().load('textures/earth.jpg');

// Create Earth-like object with texture
const earthGeometry = new THREE.SphereGeometry(1, 32, 32);
const earthMaterial = new THREE.MeshPhongMaterial({ map: earthTexture });
const earth = new THREE.Mesh(earthGeometry, earthMaterial);
scene.add(earth);
earth.castShadow = true;

// Create directional light representing the sun
const sunLight = new THREE.DirectionalLight(0xffffff, 1);
scene.add(sunLight);
sunLight.castShadow = true;

// const helper = new THREE.DirectionalLightHelper(sunLight, 5);
// scene.add(helper);

// Set up clock for animation
const clock = new THREE.Clock();

// Create OrbitControls
const controls = new OrbitControls(camera, renderer.domElement);
controls.enableDamping = true; // an animation loop is required when either damping or auto-rotation are enabled
controls.dampingFactor = 0.25;
controls.screenSpacePanning = false;
controls.maxPolarAngle = Math.PI / 2; // Limit how high you can look up (in radians)

// Update function
const update = () => {
  const delta = clock.getDelta();

  // Rotate the Earth
  earth.rotation.y += 0.1 * delta;

  // Rotate the sun around the Earth
  const sunSpeed = 0.5;
  const angle = clock.elapsedTime * sunSpeed;
  const distance = 10;
  sunLight.position.set(Math.cos(angle) * distance, 0, Math.sin(angle) * distance);

  // Render the scene
  renderer.render(scene, camera);

  // Call update again on the next frame
  requestAnimationFrame(update);

  // Update OrbitControls
  controls.update();
};

// Start the animation loop
update();

// Handle window resize
window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});
